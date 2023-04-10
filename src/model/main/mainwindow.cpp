// The core program of mainwindow
#include"mainwindow.hpp"

#include"../widget/tipwindow.hpp"
#include"../../standard.hpp"
#include"../../net/net.hpp"
#include"../../net/netcontroller.hpp"

#include<fstream>
#include<mutex>
#include<thread>

#include<cstdio>

#include<QtWidgets/qlabel.h>
#include<QtWidgets/qscrollbar.h>
#include<QtGui/qkeysequence.h>
#include<QtGui/qpixmap.h>

using namespace std;

//Shared variables.
standard::dataStruct::UserData userData;
net::NetController* netController;

extern net::Client* clientNet;
extern std::mutex netMutexLock;

//private:
void MainWindow::setupView() {
	setWindowFlag(Qt::FramelessWindowHint);
	view.setupUi(this);
}

void MainWindow::setupDelegate() const{
	//Window Connection
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), this,SLOT(showMinimized()));
	QObject::connect(view.closeButton, SIGNAL(pressed()), this, SLOT(userQuit()));

	//Option Connection    --- For registering Page&List only.
	QObject::connect(view.comChatOption, SIGNAL(pressed()), this, SLOT(comChatOptionSlot()));
	QObject::connect(view.engLearnOption, SIGNAL(pressed()), this, SLOT(engLearnOptionSlot()));
	QObject::connect(view.engLearnOption_2, SIGNAL(pressed()), this, SLOT(egOptionSlot()));
}

void MainWindow::setupNetController() const{
	Pages.comChat->setupNetController();
}

void MainWindow::serveFor(int option) 
{
	if(status.curList != nullptr)
		status.curList->close();
	if(status.curPage != nullptr)
		status.curPage->close();

	switch (option)
	{
	case OptionList::comChat:
		status.curList = Lists.comChat;
		status.curPage = Pages.comChat;
		break;
	case OptionList::engLearn:
		status.curList = Lists.engLearn;
		status.curPage = Pages.engLearn;
		break;
	case OptionList::egService:
		status.curList = Lists.service;
		status.curPage = Pages.service;
		break;
	}

	status.curList->show();
	status.curPage->show();
}

void MainWindow::generateService()
{
	Pages.comChat = new Page::ComChat(view.mainArea);
	Lists.comChat = new List::ComChat(view.listArea);

	Pages.engLearn = new Page::EngLearn(view.mainArea);
	Lists.engLearn = new List::EngLearn(view.listArea);

	Pages.service = new Page::ServicePage(view.mainArea);
	Lists.service = new List::ServiceList(view.listArea);
}

//public:
void MainWindow::keyPressEvent(QKeyEvent* event) {
	if (event->matches(QKeySequence::Cancel))
		userQuit();
}

void  MainWindow::mousePressEvent(QMouseEvent* event)
{
	status.mousePoint = event->globalPos();
	if (status.mousePoint.y() < this->y()+ view.infoArea->height())
	{
		windowMovingOn = true; 
	}
}

void  MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
	if(windowMovingOn)
	{
		QPoint newMousPoint;
		int deltaX, deltaY;

		newMousPoint = event->globalPos();

		deltaX = newMousPoint.x() - status.mousePoint.x();
		deltaY = newMousPoint.y() - status.mousePoint.y();

		move(x() + deltaX, y() + deltaY);
		windowMovingOn = false;
	}
}

MainWindow::MainWindow(QWidget* parent)
	:QWidget(parent),windowMovingOn(false)
{
	status.curPage = nullptr;
	status.curList = nullptr;
	status.mousePoint = QPoint();

	setupView();
	setupDelegate();

	setMouseTracking(true);

	close();
}

//public slots:
void MainWindow::init() {
	fstream selfProfileFile;
	char* selfProfileBuffer, fileSizeStr[standard::size::fieldBytes];
	char32_t* selfUsernameBuffer;
	int profileBufferSize;

	//Allocate
	selfUsernameBuffer = new char32_t[net::sockMsgLen];
	selfProfileFile.open(standard::file::selfProfile, ios_base::out);
	
	memset(selfUsernameBuffer,0,net::sockMsgBytes);
	memset(fileSizeStr, 0, standard::size::fieldBytes);

	//Recv
	clientNet->recvMsg(selfUsernameBuffer);
	clientNet->recvFile(fileSizeStr, standard::size::fieldBytes);
	char* end;		
	
	profileBufferSize = strtol( fileSizeStr, &end, 10);
	selfProfileBuffer = new char[profileBufferSize];
	memset(selfProfileBuffer, 0, profileBufferSize);
		
	clientNet->recvFile(selfProfileBuffer, profileBufferSize);
	//Intermidiate
	auto fd = fopen(standard::file::selfProfile,"wb");
	fwrite(selfProfileBuffer, sizeof(char), profileBufferSize, fd);
	fclose(fd);
	
	/*
	Initilize: 
		1)		userData struct, 
		2)		info area, 
		3)		net controller thread.
		4)		allocate memory for service class.-> generateService()
	*/
	userData.selfUsername = QString::fromStdU32String(selfUsernameBuffer);
	userData.selfProfileFilename = standard::file::selfProfile;
	selfProfileFile.open(standard::file::selfProfile, ios_base::in);

	view.usernameLabel->setText(userData.selfUsername);
	view.profileLabel->setPixmap(QPixmap(standard::file::selfProfile));
	selfProfileFile.close();

	netController = new net::NetController;
	std::thread netControllerThread(net::netControllerEntry, netController);
	netControllerThread.detach();
	
	generateService();
	//NetController Register
	setupNetController();

	//Free
	delete[] selfProfileBuffer;
	delete[] selfUsernameBuffer;
	
	show();
}

//private slots:
void MainWindow::userQuit()
{
	QString cmdString(QString::fromStdU32String(U"USERQUIT "));
	char32_t* msg = new char32_t[net::sockMsgLen];

	cmdString.append(userData.selfID);
	memset(msg, 0, net::sockMsgBytes);
	memcpy(msg, cmdString.toStdU32String().c_str(), cmdString.size() * sizeof(char32_t));
	clientNet->sendMsg(msg);

	delete[] msg;
	close();
}

void MainWindow::comChatOptionSlot() 
{
	serveFor(OptionList::comChat);
}

void MainWindow::engLearnOptionSlot()
{
	serveFor(OptionList::engLearn);
}

void MainWindow::egOptionSlot()
{
	serveFor(OptionList::egService);
}
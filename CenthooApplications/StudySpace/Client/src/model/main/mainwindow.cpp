#include"mainwindow.hpp"

#include"../widget/tipwindow.hpp"
#include"../../standard.hpp"
#include"../../net/net.hpp"
#include"../../net/netcontroller.hpp"

#include<fstream>
#include<mutex>
#include<thread>

#include<cstdio>
#include<malloc.h>

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
void MainWindow::setupUi() {
	setWindowFlag(Qt::FramelessWindowHint);
	view.setupUi(this);

	Pages.comChat = new ChatPage(view.mainArea);
	Pages.comChat->setSelfProfile(userWindowData.selfProfile);
	Lists.comChat = new List::ComChat(view.listArea);

	Pages.engLearn = new Page::EngLearn(view.mainArea);
	Lists.engLearn = new List::EngLearn(view.listArea);

	userWindowData.selfProfile = new QPixmap;
}

void MainWindow::setuiDelegate() {
	//Window Connection
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), this,SLOT(showMinimized()));
	QObject::connect(view.closeButton, SIGNAL(pressed()), this, SLOT(close()));

	//Option Connection
	QObject::connect(view.comChatOption, SIGNAL(pressed()), this, SLOT(comChatOptionSlot()));
	QObject::connect(view.engLearnOption, SIGNAL(pressed()), this, SLOT(engLearnOptionSlot()));
}

void MainWindow::setupNetController() {
	Pages.comChat->setupNetController();
}

void MainWindow::windowController(int option) 
{
	if(status.curList)
		status.curList->close();
	if(status.curPage)
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
	}

	status.curList->show();
	status.curPage->show();
}


//public:
void MainWindow::keyPressEvent(QKeyEvent* event) {
	if (event->matches(QKeySequence::Cancel))
		close();
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
	:QWidget(parent)
{
	status.curPage = nullptr;
	status.curList = nullptr;
	status.mousePoint = QPoint();
	windowMovingOn = false;

	setupUi();
	setuiDelegate();

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
	
	//Initilize
	userData.selfUsername = QString::fromStdU32String(selfUsernameBuffer);
	selfProfileFile.open(standard::file::selfProfile, ios_base::in);
	*userWindowData.selfProfile =  QPixmap(standard::file::selfProfile);

	view.usernameLabel->setText(userData.selfUsername);
	view.profileLabel->setPixmap(*userWindowData.selfProfile);
	selfProfileFile.close();

	netController = new net::NetController;
	std::thread netControllerThread(net::netControllerEntry, netController);
	netControllerThread.detach();
	
	Pages.comChat->setSelfProfile(userWindowData.selfProfile);

	//NetController Register
	setupNetController();

	//Free
	delete[] selfProfileBuffer;
	delete[] selfUsernameBuffer;
	
	show();
}

//private slots:

void MainWindow::comChatOptionSlot() {
	windowController(OptionList::comChat);
}

void MainWindow::engLearnOptionSlot()
{
	windowController(OptionList::engLearn);
}
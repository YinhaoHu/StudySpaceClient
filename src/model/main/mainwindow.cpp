// The core program of mainwindow
#include"mainwindow.hpp"

#include"model/widget/tipwindow.hpp"
#include"standard.hpp"
#include"net/net.hpp"
#include"net/netcontroller.hpp"
#include"data/runtime_datamanager.hpp"
#include"data/local_datamanager.hpp"

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
std::mutex NetControllerMutexLock;
TipWindow* tipWindow;
QSharedPointer<data::Runtime_DataManager> runtime_dataManager(new data::Runtime_DataManager);
QSharedPointer<data::Local_DataManager> local_dataManager(new data::Local_DataManager);

extern net::Client* clientNet;
extern std::mutex netMutexLock;

//private:
void MainWindow::setupView() {
	setWindowFlag(Qt::FramelessWindowHint);
	view.setupUi(this);
}

void MainWindow::setupDelegate() const{
	//Window Connection
	connect(view.minimizeButton, SIGNAL(pressed()), SLOT(toggle()));
	connect(view.minimizeButton, SIGNAL(pressed()), this,SLOT(showMinimized()));
	connect(view.closeButton, SIGNAL(pressed()), this, SLOT(userQuit()));
	
	//Miscellanea
	connect(view.userinfoOption, SIGNAL(pressed()), this, SLOT(userinfoOptionSlot()));

	//Option Connection    --- For registering Page&List only.
	connect(view.comChatOption, SIGNAL(pressed()), this, SLOT(comChatOptionSlot()));
	connect(view.engLearnOption, SIGNAL(pressed()), this, SLOT(engLearnOptionSlot()));
	connect(view.contactsOption, SIGNAL(pressed()), this, SLOT(contactsOptionSlot()));
	
}

void MainWindow::setupNetController() const{
	Pages.comChat->setupNetController();
}

void MainWindow::serveFor(OptionList option) 
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
	case OptionList::contacts:
		status.curList = Lists.contacts;
		status.curPage = Pages.contacts;
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

	//Namespace might cause problem, don't use it anymore.
	Pages.contacts = new ContactsPage(view.mainArea);
	Lists.contacts = new ContactsList(view.listArea);
	Lists.contacts->setRelatedPage(Pages.contacts);
}

void MainWindow::generateMiscellanea()
{
	::tipWindow = new TipWindow;
	userinfo_selfshow_window = new Userinfo_SelfShow_Window();
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

	setMouseTracking(true);

	close();
}

//public slots:
void MainWindow::init() {
	auto recv0_id = clientNet->easyRecv_QString_U32();
	auto recv1_username = clientNet->easyRecv_QString_U32();
	auto recv2_intro = clientNet->easyRecv_QString_U32();
	auto recv3_profile = clientNet->easyRecv_File();

	//Intermidiate
	auto profileFile = fopen(standard::file::selfProfile,"wb");
	fwrite(recv3_profile->data.get(), sizeof(char), recv3_profile->bytes, profileFile);
	fclose(profileFile);

	/*
	Initilize: 
		*)		tipwinodw
		*)		net controller thread.
		*)		allocate memory for service class.-> generateService(),generateMiscellanea().
		*)		related global variables: 
	*/

	//Initialize runtime_dataManager
	local_dataManager->setupLocalDataInfo(recv0_id->toLong());

	runtime_dataManager->add_personalInfo_smallProfileObject(view.profileLabel);
	runtime_dataManager->add_personalInfo_usernameObject(view.usernameLabel);

	runtime_dataManager->update_personalInfo_profile();
	runtime_dataManager->update_personalInfo_username(std::move(*recv1_username));
	runtime_dataManager->update_personalInfo_intro(std::move(*recv2_intro));

	::netController = new net::NetController;
	std::thread netControllerThread(net::netControllerEntry, netController);
	netControllerThread.detach();

	generateService();
	generateMiscellanea();
	setupDelegate();


	//NetController Register

	setupNetController();


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

void MainWindow::userinfoOptionSlot()
{
	userinfo_selfshow_window->setInfo(
		std::move(userData.selfID), runtime_dataManager->get_personalInfo_username(),
		QPixmap(runtime_dataManager->get_personalInfo_bigProfile()), std::move(runtime_dataManager->get_personalInfo_intro()));
	userinfo_selfshow_window->display();
}

void MainWindow::contactsOptionSlot()
{
	Lists.contacts->init();
	serveFor(OptionList::contacts);
}

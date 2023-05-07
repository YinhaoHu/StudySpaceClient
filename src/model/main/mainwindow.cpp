// The core program of mainwindow
#define  _MAINWINDOW_

#include"mainwindow.hpp"

#include"model/widget/tipwindow.hpp"
#include"standard.hpp"
#include"net/net.hpp"
#include"net/netcontroller.hpp"
#include"inc_data/extern_data.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"inc_net/extern_net.hpp"

#include<fstream>
#include<mutex>
#include<thread>

#include<cstdio>

#include<QtWidgets/qlabel.h>
#include<QtWidgets/qscrollbar.h>
#include<QtGui/qkeysequence.h>
#include<QtGui/qpixmap.h>

using namespace std;
volatile bool netController_inited = false;

//private:
void MainWindow::setupView() {
	setWindowFlag(Qt::FramelessWindowHint);
	view.setupUi(this);

	view.homepageimage->setPixmap(QPixmap(standard::file::homepageImage));
}

void MainWindow::setupDelegate() const{
	//Window Connection
	connect(view.minimizeButton, SIGNAL(pressed()), SLOT(toggle()));
	connect(view.minimizeButton, SIGNAL(pressed()), this,SLOT(showMinimized()));
	connect(view.closeButton, SIGNAL(pressed()), this, SLOT(userQuit()));
	
	//Miscellanea
	connect(view.userinfoOption, SIGNAL(pressed()), this, SLOT(userinfoOptionSlot()));
	connect(view.feedBackOption, SIGNAL(pressed()), this, SLOT(feedbackOptionSlot()));

	//Option Connection    --- For registering Page&List only.
	connect(view.chatOption, SIGNAL(pressed()), this, SLOT(chatOptionSlot()));
	connect(view.engLearnOption, SIGNAL(pressed()), this, SLOT(engLearnOptionSlot()));
	connect(view.contactsOption, SIGNAL(pressed()), this, SLOT(contactsOptionSlot()));
	connect(view.studyAidsOption, SIGNAL(pressed()), this, SLOT(studyAidsOptionSlot()));

	//	For notice in main window.
	connect(netController, SIGNAL(noticeService_chat()), this, SLOT(notice_chatService()));
	connect(view.chatOption, SIGNAL(pressed()), this, SLOT(disnotice_chatService()));
	connect(netController, SIGNAL(noticeService_contacts()), this, SLOT(notice_contactsService()));
	connect(view.contactsOption, SIGNAL(pressed()), this, SLOT(disnotice_contactsService()));
}

void MainWindow::serveFor(OptionList option) 
{
	if(status.curList != nullptr)
		status.curList->close();
	if(status.curPage != nullptr)
		status.curPage->close();

	switch (option)
	{
	case OptionList::chat:
		status.curList = Lists.chat;
		status.curPage = Pages.chat;
		break;
	case OptionList::engLearn:
		status.curList = Lists.engLearn;
		status.curPage = Pages.engLearn;
		break;
	case OptionList::contacts:
		status.curList = Lists.contacts;
		status.curPage = Pages.contacts;
		break;
	case OptionList::studyAids:
		status.curList = Lists.studyAids;
		status.curPage = Pages.studyAids;
	}

	status.curList->show();
	status.curPage->show();
}

void MainWindow::generateService()
{
	//	  In generate part, it's allowed only memory allocate, 
	//	  Loading the data from local is forbidden.	

	Pages.chat = new ChatPage(view.mainArea);
	Lists.chat = new ChatList(view.listArea);

	Pages.engLearn = new Page::EngLearn(view.mainArea);
	Lists.engLearn = new List::EngLearn(view.listArea);

	//Namespace might cause problem, don't use it anymore.
	Pages.contacts = new ContactsPage(view.mainArea);
	Lists.contacts = new ContactsList(view.listArea);

	Pages.studyAids = new StudyAidsPage(view.mainArea);
	Lists.studyAids = new StudyAidsList(view.listArea);

	//Init the connections of the services.
	Lists.contacts->setRelatedPage(Pages.contacts);
	Lists.chat->setRealatedPage(Pages.chat);

		// Contacts
	connect(Pages.contacts, &ContactsPage::openDialog,
		Lists.chat, &ChatList::jumpToDialog_slot);
	connect(Pages.contacts, SIGNAL(jumpToChat_signal()),
		this, SLOT(chatOptionSlot()));

		// Chat
	connect(Lists.chat, &ChatList::privateChat_noticeOpenPage_signal,
		Pages.chat, &ChatPage::privateDialog_open_slot);
	connect(Lists.chat, &ChatList::privateChat_noticeRemovePage_signal,
		Pages.chat, &ChatPage::privateDialog_remove_slot);
		
		// Study Aids
	connect(Lists.studyAids, &StudyAidsList::noticePageSwitchToWidget,
		Pages.studyAids, &StudyAidsPage::switchToWidget);

}

void MainWindow::generateMiscellanea()
{
	//	  In generate part, it's allowed only memory allocate, 
	//	  Loading the data from local is forbidden.	

	this->miscellanea.userinfo_selfshow_window = new Userinfo_SelfShow_Window();
	this->miscellanea.feedBack_window = new FeedBackWindow();
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
	:QWidget(parent), windowMovingOn(false),
	status{nullptr, nullptr, QPoint()},
	miscellanea{ nullptr, nullptr }
{
	setupView();
	setMouseTracking(true);

	close();
}

MainWindow::~MainWindow()
{

}

//public slots:
void MainWindow::init() 
{
	//Perfect order.
	initNetControllerThread();

	setupDelegate();
	generateService();
	generateMiscellanea();

	initUserNetData();

	initUserLocalData();
	initUserRuntimeData();

	initNotification();
	initNetcontroller();

	show();
	tipWindow->closeWindow();
}

//private slots:
void MainWindow::userQuit()
{
	this->miscellanea.feedBack_window->close();
	this->miscellanea.userinfo_selfshow_window->close();

	close();
	delete this;
}

void MainWindow::notice_contactsService()
{
	if(status.curList != Lists.contacts)
		view.contactsOption->setStyleSheet(noticeServiceStyle);
}

void MainWindow::disnotice_contactsService()
{
	view.contactsOption->setStyleSheet(disnoticeServiceStyle);
}

void MainWindow::notice_chatService()
{
	if (status.curList != Lists.chat)
		view.chatOption->setStyleSheet(noticeServiceStyle);
}

void MainWindow::disnotice_chatService()
{
	view.chatOption->setStyleSheet(disnoticeServiceStyle);
}

//Serve part
void MainWindow::chatOptionSlot()
{
	serveFor(OptionList::chat);
}

void MainWindow::engLearnOptionSlot()
{
	serveFor(OptionList::engLearn);
}

void MainWindow::contactsOptionSlot()
{
	Lists.contacts->init();
	serveFor(OptionList::contacts);
}

void MainWindow::studyAidsOptionSlot()
{
	serveFor(OptionList::studyAids);
}

//Miscellanea

void MainWindow::userinfoOptionSlot()
{
	miscellanea.userinfo_selfshow_window->setInfo(
		std::move(QString::number(local_dataManager->getUserID())), runtime_dataManager->get_personalInfo_username(),
		QPixmap(runtime_dataManager->get_personalInfo_bigProfile()), std::move(runtime_dataManager->get_personalInfo_intro()));
	if (miscellanea.userinfo_selfshow_window->isHidden() == false)
		miscellanea.userinfo_selfshow_window->raise();
	else
		miscellanea.userinfo_selfshow_window->display();
}

void MainWindow::feedbackOptionSlot()
{
	if (this->miscellanea.feedBack_window->isHidden() == false)
		this->miscellanea.feedBack_window->raise();
	else
		this->miscellanea.feedBack_window->show();
}

//Init Part
void MainWindow::initUserNetData()const
{
	//Include: personal info, friends list with info

	//Section A: personal info (Old version communication)
	{
		auto recv0_id = clientNet->easyRecv_QString_U32();
		auto recv1_username = clientNet->easyRecv_QString_U32();
		auto recv2_intro = clientNet->easyRecv_QString_U32();
		auto recv3_profile = clientNet->easyRecv_File();

		local_dataManager->setupLocalDataInfo(recv0_id->toULong());

		auto filename = local_dataManager->getSelfProfile_filename();
		auto profileFile = fopen(filename.toStdString().c_str(), "wb");
		fwrite(recv3_profile->data.get(), sizeof(char), recv3_profile->bytes, profileFile);
		fclose(profileFile);

		runtime_dataManager->update_personalInfo_profile();
		runtime_dataManager->update_personalInfo_username(std::move(*recv1_username));
		runtime_dataManager->update_personalInfo_intro(std::move(*recv2_intro));
	}
	
	//Section B: friendsInfo (Easy version communication)
	{
		//Remember to delete the old code in net controller.
		clientNet->easySend_Request(std::move(QString("GETFRIENDSLIST")), local_dataManager->getUserID());
		net::remote_getFriendListOK_hander();
	}

}

void MainWindow::initNotification()const
{
	{
		unique_lock lock(netMutexLock);

		auto request = new QString("GET_NOTIFICATION ");
		request->append(QString::number(local_dataManager->getUserID()));
		clientNet->easySend_Msg(std::move(*request));
		delete request;
	}
}

void MainWindow::initNetControllerThread()const
{
	::netController= new net::NetController;
	std::thread netControllerThread(net::netControllerEntry, netController);
	netControllerThread.detach();
}

void MainWindow::initUserRuntimeData()const
{
	runtime_dataManager->add_personalInfo_smallProfileObject(view.profileLabel);
	runtime_dataManager->add_personalInfo_usernameObject(view.usernameLabel);

	this->miscellanea.userinfo_selfshow_window->setupRuntimeDataManager();
}

void MainWindow::initNetcontroller()const
{
	Pages.chat->setupNetController();
	Lists.chat->setupNetController();

	Lists.contacts->setupNetController();

	netController_inited = true;
	//
}

void MainWindow::initUserLocalData()const
{
	::local_dataManager->loadPrivateChatData();

	Lists.chat->setupLocalData();
	Pages.chat->setupLocalData();

	Pages.studyAids->setupLocalDatamanager();
}

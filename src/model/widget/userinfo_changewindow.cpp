#include"userinfo_changewindow.hpp"
#include"tipwindow.hpp"
#include"standard.hpp"
#include"net/netcontroller.hpp"
#include"net/net.hpp"
#include"data/runtime_datamanager.hpp"

#include<sys/stat.h>
#include<mutex>
#include<fstream>
#include<qfiledialog.h>

using namespace std;

extern TipWindow* tipWindow;//From mainwindow.cpp
extern net::NetController* netController;
extern std::mutex NetControllerMutexLock;
extern net::Client* clientNet;
extern std::mutex netMutexLock;
extern standard::dataStruct::UserData userData;
extern QSharedPointer<data::Runtime_DataManager> runtime_dataManager;

static void sendMsgToGetOldPassword()
{
	char32_t* msg_cstr = new char32_t[net::sockMsgLen];
	QString msgStr("USERINFO_CHANGE_GET_OLDPASSWORD ");
	msgStr.append(userData.selfID);

	memset(msg_cstr, 0, net::sockMsgBytes);
	memcpy(msg_cstr, msgStr.toStdU32String().c_str(), net::sockMsgBytes);

	{
		unique_lock lock(netMutexLock);
		clientNet->sendMsg(msg_cstr);
	}
	delete[] msg_cstr;
}

//private:
bool Userinfo_Change_Window::oldPassWordMatch()
{
	QString* inputPassword = new QString(view.oldpasswordInput->text());
	bool res;

	while (oldPassword == nullptr)
		;
	res = inputPassword->compare(*oldPassword);//Safe

	delete inputPassword;

	return (res == 0);
}

void Userinfo_Change_Window::setupNetController()
{
	connect(netController, SIGNAL(password_update_signal() ),
		this, SLOT(password_update_slot() ),Qt::DirectConnection );

	connect(netController, SIGNAL(changeInfo_update_signal()),
		this, SLOT(userinfo_change_okResponse_update()));
}

void Userinfo_Change_Window::setupDelegate()
{
	connect(view.saveButton, SIGNAL(pressed()), this, SLOT(doChangeInfo()));
	connect(view.newProfile, SIGNAL(pressed()), fileDialog, SLOT(show()));//FILE DIALOG
	connect(tipWindow, SIGNAL(tipWindow->confirmed()), this, SLOT(deleteWindow()));
	connect(view.quitButton, SIGNAL(pressed()), this, SLOT(deleteWindow()));
}

void Userinfo_Change_Window::setupView()
{
	view.setupUi(this);
	setWindowFlag(Qt::FramelessWindowHint);

	fileDialog->close();
}

//public

Userinfo_Change_Window::Userinfo_Change_Window()
	:oldPassword(nullptr), fileDialog(fileDialog = new QFileDialog)
{
	setupView();
	setupNetController();
	setupDelegate();
}

Userinfo_Change_Window::~Userinfo_Change_Window()
{
	delete fileDialog;
}

void Userinfo_Change_Window::
setOldInfo(QString&& username, QPixmap&& profile, QString&& intro)
{
	view.profileLabel->setPixmap(profile);
	view.usernameInput->setText(username);
	view.introInput->setText(intro);
}


//public slots:

void Userinfo_Change_Window::doChangeInfo()
{	
	if(oldPassword == nullptr)
		sendMsgToGetOldPassword();

	if(oldPassWordMatch())
	{
		/*
		Send:

		PROG ID	(char*)	-> prog = CHANGEUSERINFO ->sockbytes

		FILESIZE ( char*) -> 16
		FILE(char*)	-> filesize
		NEW-NAME(char32t)	-> sockbytes
		NEW-PASSWORD(char)	-> sockbytes
		NEW-INTRO(char32t)	-> sockbytes
		*/
		bool changedProfile = true;

		auto selectedFile = fileDialog->selectedFiles();
		QString filename;
		if (selectedFile.isEmpty())
			filename = standard::file::selfProfile;
		else
			filename = selectedFile.front();
		//BEGIN
		QString beginQStr("CHANGEUSERINFO ");
		beginQStr.append(userData.selfID);

		char32_t* send0_begin = new char32_t[net::sockMsgLen];
		memset(send0_begin, 0, net::sockMsgBytes);
		memcpy(send0_begin, beginQStr.toStdU32String().c_str(), sizeof(char32_t)* beginQStr.length());

		//FILESIZE & FILE
		char* send1_size = new char[16];
		QString sizeqstr;
		
		QFile* profileFile = new QFile(filename);
		profileFile->open(QIODevice::ReadOnly | QIODevice::Unbuffered);
		auto data = profileFile->readAll();
		size_t profileSize = data.size();

		if (profileSize >= net::sockMsgBytes * 1000)
		{
			tipWindow->inform(U"头像文件最大4MB");
			return;
		}

		sizeqstr.setNum(profileSize);
		strcpy(send1_size, sizeqstr.toStdString().c_str());

		char* send2_file  = new char[profileSize];
		memset(send2_file, 0, profileSize);
		memcpy(send2_file, data.constData(), profileSize);

		//NEW-NAME
		char32_t* send3_name = new char32_t[net::sockMsgLen];
		memset(send3_name, 0, net::sockMsgBytes);
		memcpy(send3_name, view.usernameInput->text().toStdU32String().c_str(), 
			sizeof(char32_t)*view.usernameInput->text().length());


		//NEW-PASSWORD
		char32_t* send4_password = new char32_t[net::sockMsgLen];
		memset(send4_password, 0, net::sockMsgBytes);
		memcpy(send4_password, view.newpasswordInput->text().toStdU32String().c_str(), 
			sizeof(char32_t)*view.newpasswordInput->text().length());

		//NEW-INTRO
		char32_t* sned5_intro = new char32_t[net::sockMsgLen];
		memset(sned5_intro, 0, net::sockMsgBytes);
		memcpy(sned5_intro, view.introInput->toPlainText().toStdU32String().c_str(), 
			sizeof(char32_t)*view.introInput->toPlainText().length());

		//SEND
		{
			unique_lock lock(netMutexLock);

			clientNet->sendMsg(send0_begin);
			
			clientNet->sendMsg(send3_name);
			clientNet->sendMsg(send4_password);
			clientNet->easySend_U32String(view.introInput->toPlainText());

			clientNet->easySend_File(std::move(filename));
		}

		FILE* oldProfile = fopen(standard::file::selfProfile, "wb");
		fwrite(send2_file,sizeof(char),profileSize,oldProfile);
		fclose(oldProfile);

		//DELETE
		
		delete[] send0_begin;
		delete[] send1_size;
		delete[] send2_file;
		delete[] send3_name;
		delete[] send4_password;
		delete[] sned5_intro;

		tipWindow->inform(U"正在修改信息...");
	}
	else
	{
		tipWindow->inform(U"原密码错误");
	}
}


void Userinfo_Change_Window::userinfo_change_okResponse_update()
{
	runtime_dataManager->update_personalInfo_profile();
	runtime_dataManager->update_personalInfo_username(std::move(view.usernameInput->text()));
	runtime_dataManager->update_personalInfo_intro(std::move(view.introInput->toPlainText()));

	tipWindow->inform(U"修改成功");
	close();
	deleteWindow();
}

void Userinfo_Change_Window::password_update_slot()
{
	{
		unique_lock lock(NetControllerMutexLock);
		oldPassword = netController->userInfo_change_data.oldPassword;
	}
}

void Userinfo_Change_Window::deleteWindow()
{
	this->close();
	delete this;
}
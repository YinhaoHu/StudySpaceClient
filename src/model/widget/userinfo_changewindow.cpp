#include"userinfo_changewindow.hpp"
#include"tipwindow.hpp"
#include"standard.hpp"
#include"net/netcontroller.hpp"
#include"net/net.hpp"
#include"data/guard.hpp"
#include"data/runtime_datamanager.hpp"
#include"inc_data/extern_data.hpp"

#include<sys/stat.h>
#include<mutex>
#include<fstream>
#include<qfiledialog.h>

using namespace std;
using namespace data::guard;

extern TipWindow* tipWindow;//From mainwindow.cpp
extern net::NetController* netController;
extern std::mutex NetControllerMutexLock;
extern net::Client* clientNet;
extern std::mutex netMutexLock;

static void sendMsgToGetOldPassword()
{
	char32_t* msg_cstr = new char32_t[net::sockMsgLen];
	QString msgStr("USERINFO_CHANGE_GET_OLDPASSWORD ");
	msgStr.append(QString::number(local_dataManager->getUserID()));

	memset(msg_cstr, 0, net::sockMsgBytes);
	memcpy(msg_cstr, msgStr.toStdU32String().c_str(), net::sockMsgBytes);

	{
		unique_lock lock(netMutexLock);
		clientNet->sendMsg(msg_cstr);
	}
	delete[] msg_cstr;
}

//private:
bool Userinfo_Change_Window::oldPassWordMatch(QString& oldpassword)
{
	auto res = view.oldpasswordInput->text().compare(oldpassword);

	return (res == 0);
}

void Userinfo_Change_Window::setupNetController()
{
	connect(netController, &net::NetController::password_update_signal,
		this, &Userinfo_Change_Window::doChange_implement);

	connect(netController, SIGNAL(changeInfo_update_signal()),
		this, SLOT(userinfo_change_okResponse_update()));
}

void Userinfo_Change_Window::setupDelegate()
{
	connect(view.saveButton, SIGNAL(pressed()), this, SLOT(doChange_entry()));
	connect(view.newProfile, SIGNAL(pressed()), fileDialog, SLOT(show()));
	connect(fileDialog, &QFileDialog::fileSelected, this, &Userinfo_Change_Window::checkAndTempShowProfile);
	connect(tipWindow, SIGNAL(tipWindow->confirmed()), this, SLOT(deleteWindow()));
	connect(view.quitButton, SIGNAL(pressed()), this, SLOT(deleteWindow()));
}

void Userinfo_Change_Window::setupView()
{
	view.setupUi(this);
	setWindowFlag(Qt::FramelessWindowHint);

	fileDialog->close();
}

void Userinfo_Change_Window::tempShowNewProfile(QString filename)
{
	view.profileLabel->setPixmap(QPixmap(filename).scaled
		(standard::scale::bigProfileSideLen, standard::scale::bigProfileSideLen));
}

void Userinfo_Change_Window::checkAndTempShowProfile(QString filename)
{
	QFileInfo finfo(filename);
	if (data::guard::isValid_readImageFormat(finfo.suffix()) == false)
		tipWindow->inform("请选择正确的图片");
	else if (finfo.size() > standard::size::profile_maxBytes)
		tipWindow->inform("图片大小不超过4MB");
	else
		tempShowNewProfile(filename);
}

//public

Userinfo_Change_Window::Userinfo_Change_Window()
	:fileDialog(fileDialog = new QFileDialog)
{
	setupView();
	setupNetController();
	setupDelegate();
}

Userinfo_Change_Window::~Userinfo_Change_Window()
{
	delete fileDialog;
}

void Userinfo_Change_Window::setOldInfo(QString&& username, QPixmap&& profile, QString&& intro)
{
	view.profileLabel->setPixmap(profile);
	view.usernameInput->setText(username);
	view.introInput->setText(intro);
}

//public slots:

void Userinfo_Change_Window::doChange_implement(QString oldpassword)
{
	bool noInvolvePassword = view.newpasswordInput->text().isEmpty() && view.oldpasswordInput->text().isEmpty();

	bool matchPassword = oldPassWordMatch(oldpassword);

	if (matchPassword || noInvolvePassword)
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
			filename = local_dataManager->getSelfProfile_filename();
		else
			filename = selectedFile.front();
		//BEGIN
		QString beginQStr("CHANGEUSERINFO ");
		beginQStr.append(QString::number(local_dataManager->getUserID()));

		char32_t* send0_begin = new char32_t[net::sockMsgLen];
		memset(send0_begin, 0, net::sockMsgBytes);
		memcpy(send0_begin, beginQStr.toStdU32String().c_str(), sizeof(char32_t) * beginQStr.length());

		//FILESIZE & FILE
		char* send1_size = new char[16];
		QString sizeqstr;

		QFile* profileFile = new QFile(filename);
		profileFile->open(QIODevice::ReadOnly | QIODevice::Unbuffered);
		auto data = profileFile->readAll();
		size_t profileSize = data.size();

		sizeqstr.setNum(profileSize);
		strcpy(send1_size, sizeqstr.toStdString().c_str());

		char* send2_file = new char[profileSize];
		memset(send2_file, 0, profileSize);
		memcpy(send2_file, data.constData(), profileSize);

		//NEW-NAME
		char32_t* send3_name = new char32_t[net::sockMsgLen];
		memset(send3_name, 0, net::sockMsgBytes);
		memcpy(send3_name, view.usernameInput->text().toStdU32String().c_str(),
			sizeof(char32_t) * view.usernameInput->text().length());


		QString password = noInvolvePassword ?  oldpassword: view.newpasswordInput->text();

		//NEW-INTRO
		char32_t* sned5_intro = new char32_t[net::sockMsgLen];
		memset(sned5_intro, 0, net::sockMsgBytes);
		memcpy(sned5_intro, view.introInput->toPlainText().toStdU32String().c_str(),
			sizeof(char32_t) * view.introInput->toPlainText().length());

		//SEND
		{
			unique_lock lock(netMutexLock);

			clientNet->sendMsg(send0_begin);

			clientNet->sendMsg(send3_name);
			clientNet->easySend_Msg(std::move(password));
			clientNet->easySend_U32String(view.introInput->toPlainText());

			clientNet->easySend_File(std::move(filename));
		}

		FILE* oldProfile = fopen( local_dataManager->getSelfProfile_filename().toStdString().c_str(), "wb");
		fwrite(send2_file, sizeof(char), profileSize, oldProfile);
		fclose(oldProfile);

		//DELETE

		delete[] send0_begin;
		delete[] send1_size;
		delete[] send2_file;
		delete[] send3_name;
		delete[] sned5_intro;

		tipWindow->inform(U"正在修改信息...");
	}
	else
	{
		tipWindow->inform(U"原密码错误");
	}
}

void Userinfo_Change_Window::doChange_entry()
{
	/*
		For easy develop, we don't make the specific change for each item.
		Just use old info replace the empty input.
	*/
	switch (isValid_UserName(view.usernameInput->text()))
	{
	case 1:
		tipWindow->inform(QString("用户名长度不超过 %1").arg(standard::guard::username_maxLen));
		return;
	case 2:
		tipWindow->inform(QString("用户名不能有空格"));
		return;
	} 

	if(!view.newpasswordInput->text().isEmpty() || !view.oldpasswordInput->text().isEmpty())
	{
		switch (isValid_password(view.newpasswordInput->text()))
		{
		case 1:
			tipWindow->inform(QString("密码仅包括字母和数字"));
			return;
		case 2:
			tipWindow->inform(QString("密码长度仅在%1~%2之间").arg(standard::guard::password_minLen).
				arg(standard::guard::password_maxLen));
			return;
		}
	}

	sendMsgToGetOldPassword();
}


//To connect

void Userinfo_Change_Window::userinfo_change_okResponse_update()
{
	runtime_dataManager->update_personalInfo_profile();
	runtime_dataManager->update_personalInfo_username(std::move(view.usernameInput->text()));
	runtime_dataManager->update_personalInfo_intro(std::move(view.introInput->toPlainText()));

	tipWindow->inform(U"信息已保存");
	close();
	deleteWindow();
}

void Userinfo_Change_Window::deleteWindow()
{
	this->close();
	delete this;
}
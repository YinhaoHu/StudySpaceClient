#include"registerwindow.hpp"
#include"../../net/net.hpp"
#include"../../../lib/CenthooLib/HTime/HTime.hpp"

#include<algorithm>
#include<string>
#include<mutex>

#include<cstring>

#include<QtGui/qkeysequence.h>

using namespace ceh::Time;
using namespace std;

extern net::Client* clientNet;//From driver.cpp
extern mutex netMutexLock;//From driver.cpp
//Aux functions
static inline bool isValidEmail(QString& emailField)
{
	uint8_t dotCount = 0;
	bool atFoundFlag = false;

	for (auto& theCh : emailField)
	{
		if (theCh == '.')
			dotCount += 1;
		else if (dotCount == 0 && theCh == '@')
			atFoundFlag = true;
	}

	return dotCount == 1 && atFoundFlag && emailField.back() != '.';
}

//Implementation: private
void RegisterWindow::inform(const char32_t* msg) {
	tipWindow->inform(msg);
}

//Implementation: public
RegisterWindow::RegisterWindow(QWidget* parent)
	:QWidget(parent)
{
	buildView();
	buildDelegate();
}

void RegisterWindow::buildView() {
	setWindowFlag(Qt::FramelessWindowHint);
	close();

	tipWindow = new TipWindow;
	view.setupUi(this);
}

void RegisterWindow::buildDelegate() {
	QObject::connect(view.closeButton, SIGNAL(pressed()), this, SIGNAL(closed()));
	QObject::connect(view.closeButton, SIGNAL(pressed()), this, SLOT(close()));

	QObject::connect(view.minimizeButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), this, SLOT(minimumSize()));

	QObject::connect(view.registerButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.registerButton, SIGNAL(pressed()), this, SLOT(doRegister()));
}

void RegisterWindow::doRegister() {
	infoFields info;
	QString allocatedID, okMsg;
	int checkStatus, serverResponseCode;

	info.username = view.nameInput->text();
	info.password = view.passwordInput->text();
	info.repassword = view.repasswordInput->text();
	info.email = view.emailInput->text();
	info.code = view.codeInput->text();

	checkStatus = checkRegister(info);
	switch (checkStatus)
	{
	case 0:break;
	case 1:inform(U"请输入所有字段"); return;
	case 2: inform(U"密码长度不能\n小于8个字符"); return;
	case 3:inform(U"两次输入密码\n不匹配"); return;
	case 4:inform(U"邮箱格式不正确"); return;
	case 5:inform(U"用户名不能超过12个字符长"); return;
	default:inform(U"客户端未知错误"); return;
	}

	netMutexLock.lock();
	sendToServer(info);

	serverResponseCode = getServerResponseCode(allocatedID);
	netMutexLock.unlock();
	switch (serverResponseCode)
	{
	case 0:
		okMsg = QString::fromStdU32String(U"注册成功，你的\nID:");
		okMsg += allocatedID;
		tipWindow->inform(okMsg.toStdU32String().c_str());
		QObject::connect(tipWindow, SIGNAL(confirmed()), this, SIGNAL(registerOk()));
		break;
	case 1:inform(U"该邮箱已经\n被用于注册"); return;
	case 2:inform(U"该用户名已经存在"); return;
	case 3:inform(U"注册码无效"); return;
	default:inform(U"服务端未知错误"); return;
	}
	
}
int RegisterWindow::checkRegister(infoFields& info)
{
	if (info.code.isEmpty() || info.email.isEmpty() || info.password.isEmpty()
		|| info.repassword.isEmpty() || info.username.isEmpty())
		return 1;
	else if (info.password.size() < 8)
		return 2;
	else if (info.password != info.repassword)
		return 3;
	else if (!isValidEmail(info.email))
		return 4;
	else if (info.username.size() > 12)
		return 5;
	return 0;
}
void RegisterWindow::sendToServer(infoFields& info) {
	char32_t* msg;
	u32string msgStr;
	HTime htime;
	QString year, month, day;

	msg = new char32_t[net::sockMsgLen] ;
	memset(msg, 0, net::sockMsgBytes);
	
	year = QString::number(htime.getYearByInt());
	month = QString::number(htime.getMonthByInt());
	day = QString::number(htime.getMDayByInt());

	msgStr.append(U"REGISTER 0 ");
	msgStr.append(info.username.toStdU32String() + U" ");
	msgStr.append(info.password.toStdU32String() + U" ");
	msgStr.append(info.code.toStdU32String() + U" ");
	msgStr.append(info.email.toStdU32String() + U" ");
	msgStr.append(year.toStdU32String()+U" ");
	msgStr.append(month.toStdU32String()+U" ");
	msgStr.append(day.toStdU32String());

	memcpy(msg, msgStr.c_str(), msgStr.size() * sizeof(char32_t));
	clientNet->sendMsg(msg);
	delete[] msg;
}
int RegisterWindow::getServerResponseCode(QString& allocatedId) {
	u32string recvMsg;
	char32_t* recvedMsg;
	int statuscode;
	
	recvedMsg = new char32_t[net::sockMsgLen];
	memset(recvedMsg, 0, net::sockMsgBytes);
	while(recvedMsg[0]==U'\0')
		clientNet->recvMsg(recvedMsg);
	recvMsg = recvedMsg;
	statuscode = -1;
	if (recvMsg.size()>2 && equal(recvMsg.begin(), recvMsg.begin() + 2, U"OK"))
	{
		allocatedId = QString::fromStdU32String(recvedMsg + 3);
		 statuscode=0;
	}
	else if (equal(recvMsg.begin(), recvMsg.end(), U"EMAIL"))
		statuscode = 1;
	else if (equal(recvMsg.begin(), recvMsg.end(), U"NAME"))
		statuscode = 2;
	else if (equal(recvMsg.begin(), recvMsg.end(), U"CODE"))
		statuscode = 3;

	delete[] recvedMsg;
	return statuscode;
}

void RegisterWindow::keyPressEvent(QKeyEvent * event) {
	if (event->matches(QKeySequence::InsertParagraphSeparator))
		view.registerButton->click();
	else if (event->matches(QKeySequence::Cancel))
	{
		close();
		emit closed();
	}
}
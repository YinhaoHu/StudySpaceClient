#include"registerwindow.hpp"
#include"net/net.hpp"
#include"standard.hpp"
#include"CenthooLib/HTime/HTime.hpp"
#include"data/guard.hpp"
#include"inc_net/extern_net.hpp"
#include"inc_tip/extern_tipwindow.hpp"

#include<algorithm>
#include<string>
#include<mutex>

#include<cstring>

#include<QtGui/qkeysequence.h>

using namespace ceh::Time;
using namespace std;
using namespace data::guard;

//Aux functions

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
	case 2: 
	{
		QString inf = QString("密码长度仅限%1~ %2").
			arg(standard::guard::password_minLen).arg(standard::guard::password_maxLen);
		inform(inf.toStdU32String().c_str()); 
		return;
	}
	case 3:inform(U"两次输入密码\n不匹配"); return;
	case 4:inform(U"邮箱格式不正确"); return;
	case 5:inform(U"密码只能包括字母和数字"); return;
	case 6:inform(QString("用户名长度不超过%1个字符").
		arg(standard::guard::username_maxLen).toStdU32String().c_str()); return;
	case 7:inform(U"用户名不能有空格"); return;
	default:inform(U"客户端未知错误"); return;
	}

	sendToServer(info);

	serverResponseCode = getServerResponseCode(allocatedID);
	switch (serverResponseCode)
	{
	case 0:
		okMsg = QString::fromStdU32String(U"注册成功，你的ID:%1").
			arg(allocatedID);
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
	auto password_status = isValid_password(info.password);
	auto username_status = isValid_UserName(info.username);

	if (info.code.isEmpty() || info.email.isEmpty() || info.password.isEmpty()
		|| info.repassword.isEmpty() || info.username.isEmpty())
		return 1;
	else if (password_status == 2)
		return 2;
	else if (info.password != info.repassword)
		return 3;
	else if (!isValid_email(info.email))
		return 4;
	else if (password_status == 1)
		return 5;
	else if (username_status == 1)
		return 6;
	else if (username_status == 2)
		return 7;
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
	int statuscode;
	
	auto recv = clientNet->easyRecv_QString_U32();

	statuscode = -1;
	if (recv->contains("OK"))
	{
		allocatedId=recv->split(' ')[1];
		statuscode = 0;
	}
	else if (recv->compare("EMAIL") == 0)
		statuscode = 1;
	else if (recv->compare("NAME") == 0)
		statuscode = 2;
	else if (recv->compare("CODE") == 0)
		statuscode = 3;

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
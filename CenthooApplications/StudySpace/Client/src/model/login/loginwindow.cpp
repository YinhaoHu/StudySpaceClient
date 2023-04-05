#include"loginwindow.hpp"
#include"../../standard.hpp"
#include"../../net/net.hpp"
#include<mutex>
#include<QtCore/qobject.h>

extern standard::dataStruct::UserData userData;//From mainwindow.cpp
extern net::Client* clientNet;//From driver.cpp
extern std::mutex netMutexLock;//From driver.cpp

LoginWindow::LoginWindow(QWidget* parent)
	:QWidget(parent)
{
	setupView();
	setupDelegate();
}

void LoginWindow::setupView() {
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

	this->tipWindow = new TipWindow;
	this->registerWindow = new RegisterWindow;
	this->infoWindow = new InfoWindow;
	view.setupUi(this);
}
void LoginWindow::setupDelegate()
{
	QObject::connect(view.loginButton, SIGNAL(pressed()), this,SLOT(doLogin()));
	QObject::connect(view.loginButton, SIGNAL(pressed()), SLOT(toggle()));

	QObject::connect(view.closeButton, SIGNAL(pressed()), this, SLOT(close()));
	QObject::connect(view.minimizeButton, SIGNAL(pressed()),SLOT(toggle()));
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), this, SLOT(showMinimized()));

	QObject::connect(view.registerButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.registerButton, SIGNAL(pressed()), this, SLOT(close()));
	QObject::connect(view.registerButton, SIGNAL(pressed()), registerWindow, SLOT(show()));
	QObject::connect(registerWindow, SIGNAL(registerOk()), this, SLOT(show()));
	QObject::connect(registerWindow, SIGNAL(registerOk()), registerWindow, SLOT(close()));
	QObject::connect(registerWindow, SIGNAL(closed()), this, SLOT(show()));

	QObject::connect(view.moreinfoButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.moreinfoButton, SIGNAL(pressed()), this,SLOT(close()));
	QObject::connect(view.moreinfoButton, SIGNAL(pressed()), infoWindow,SLOT(show()));
	QObject::connect(infoWindow, SIGNAL(closed()), this, SLOT(show()));
}

void LoginWindow::keyPressEvent(QKeyEvent* event)
{
	if (event->matches(QKeySequence::Cancel))
		close();
	else if (event->matches(QKeySequence::InsertParagraphSeparator))
		doLogin();
}

void LoginWindow::mousePressEvent(QMouseEvent* event)
{
	mousePoint = event->globalPos();
	if (mousePoint.y() < this->y() + view.titleLabel->height())
	{
		windowMovingOn = true;
	}
}
void LoginWindow::mouseReleaseEvent(QMouseEvent* event)
{
	if (windowMovingOn)
	{
		QPoint newMousPoint;
		int deltaX, deltaY;

		newMousPoint = event->globalPos();

		deltaX = newMousPoint.x() - mousePoint.x();
		deltaY = newMousPoint.y() - mousePoint.y();

		move(x() + deltaX, y() + deltaY);
		windowMovingOn = false;
	}
}

void LoginWindow::doLogin() {
	QString number, password;
	int loginValid, loginState;

	number = view.numberInput->text();
	password = view.passwordInput->text();
	loginValid = checkLogin(number, password);

	switch (loginValid)
	{
	case 0:
		netMutexLock.lock();
		sendLoginInfo(number, password); 
		netMutexLock.unlock();
		break;
	case 1:
		informUser(U"请输入有效账号"); return;
	case 2:
		informUser(U"请输入密码"); return;
	case 3:
		informUser(U"请输入账号"); return;
	}

	netMutexLock.lock();
	loginState = recvLoginState();
	netMutexLock.unlock();

	if (loginState == 0)
	{
		userData.selfID = number;
		emit properLogin();
		delete this;
	}
	else if (loginState == 1)
		informUser(U"用户名或密码\n输入错误");
	else if (loginState == 2)
		informUser(U"不存在该用户");
	else if (loginState == 3)
		informUser(U"该用户已在线");
	else
		informUser(U"与服务器连接失败");
}

int LoginWindow::checkLogin(QString& number, QString& password)
{
	if (number.isEmpty())
		return 3;
	else if (password.isEmpty())
		return 2;
	else if(number.size() > 12)
		return 1;

	for (const auto& x : number)
	{
		if (!x.isDigit())
			return 1;
	}
	
	return 0;
}
void LoginWindow::sendLoginInfo(QString& number, QString& password) {
	QString msg;
	
	msg = "LOGIN ";
	msg.push_back(number);
	msg.append(" ");
	msg.push_back(password);
	
	clientNet->sendMsg(msg.toStdU32String().c_str());
}
int LoginWindow::recvLoginState() {
	char32_t* msg;
	std::u32string msgStr;
	int statusCode;

	msg = new char32_t[net::sockMsgLen];
	memset(msg, 0, net::sockMsgBytes);
	while (0 == msg[0])
		 clientNet->recvMsg(msg);
	msgStr = std::u32string(msg);
	
	statusCode = -1;
	if (std::equal(msgStr.begin(), msgStr.end(), U"OK"))
		statusCode = 0;
	else if (std::equal(msgStr.begin(), msgStr.end(), U"WRONG"))
		statusCode = 1;
	else if (std::equal(msgStr.begin(), msgStr.end(), U"NOTEXIST"))
		statusCode = 2;
	else if (std::equal(msgStr.begin(), msgStr.end(), U"LOGINED"))
		statusCode = 3;
	else
		statusCode = -1;

	delete[] msg;
	return statusCode;
}
void LoginWindow::informUser(const char32_t* msg) {
	tipWindow->inform(msg);
}

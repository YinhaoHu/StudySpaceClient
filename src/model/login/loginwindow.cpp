//For loginwindow.

#define _CRT_SECURE_NO_WARNINGS

#include"loginwindow.hpp"
#include"CenthooLib/HTime/HTime.hpp"
#include"standard.hpp"
#include"net/net.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"inc_data/extern_data.hpp"
#include"inc_data/extern_config.hpp"

#include<string>
#include<mutex>

#include<QtCore/qobject.h>

using namespace std;
using namespace ceh::Time;

static volatile uint localID;

extern net::Client* clientNet;//From driver.cpp
extern std::mutex netMutexLock;//From driver.cpp

//private:
uint LoginWindow::checkAutoLogin() const
{
	HTime timeinfo;
	auto& config = ::config_manager;

	if (config->valid_autoLoginData())
	{
		return 3;
	}

	uint ret;

	localID = config->get_autoLoginID().toULong();

	if (
		(config->get_autoLoginExpireYear().toULong() >= timeinfo.getYearByInt())
		&& (config->get_autoLoginExpireMonth().toULong() >= timeinfo.getMonthByInt())
		&& (config->get_autoLoginExpireDay().toULong() >= timeinfo.getMDayByInt())
		)
	{

		char32_t* msg = new char32_t[net::sockMsgLen];
		QString qmsg =QString("AUTOLOGIN %1").arg(localID);

		memset(msg, 0, net::sockMsgBytes);
		memcpy(msg, qmsg.toStdU32String().c_str(), net::sockMsgBytes);

		{
			unique_lock lock(netMutexLock);
			clientNet->sendMsg(msg);
			auto isOnline = clientNet->easyRecv_QString_U32(); 

			if (isOnline->compare(QString("AUTOLOGIN_ISONLINE")) == 0)
				ret = 2;
			else
			{
				tipWindow->inform("登陆成功，正在加载用户信息...");
				ret = 1;
			}
		}
		
	}
	else
		ret = 3;

	//1:ok --- 2:online -- 3:need to login
	return ret;
}

void LoginWindow::setAutoLoginData()const
{
	HTime timeInfo;
	auto& config = config_manager;
	//Format: USERID YEAR MONTH DAY
	QString y, m, d;

	y.setNum(timeInfo.getYearByInt());
	m.setNum(timeInfo.getMonthByInt());
	d.setNum(timeInfo.getMDayByInt()+this->autoLoginExpiryDays);

	config->set_autoLoginExpireYear(std::move(y));
	config->set_autoLoginExpireMonth(std::move(m));
	config->set_autoLoginExpireDay(std::move(d));
	config->set_autoLoginID(QString::number(localID));
}

//public:
LoginWindow::LoginWindow(QWidget* parent)
	:QWidget(parent)
{
	setupView();
	setupDelegate();
}

void LoginWindow::setupView() {
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

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
	if (!isHidden() && mousePoint.y() < this->y() + view.titleLabel->height())
	{
		windowMovingOn = true;
	}
}

void LoginWindow::mouseReleaseEvent(QMouseEvent* event)
{
	if (!isHidden() && windowMovingOn)
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

//private slots:
void LoginWindow::doLogin() {
	QString number, password;
	int loginValid, loginState;

	number = view.numberInput->text();
	password = view.passwordInput->text();
	loginValid = checkLogin(number, password);

	switch (loginValid)
	{
	case 0:
		sendLoginInfo(number, password); 
		break;
	case 1:
		informUser(U"请输入有效账号"); return;
	case 2:
		informUser(U"请输入密码"); return;
	case 3:
		informUser(U"请输入账号"); return;
	}

	loginState = recvLoginState();

	if (loginState == 0)//Login permited.
	{
		tipWindow->inform("登陆成功，正在加载用户信息...");
		localID= number.toULong();
		setAutoLoginData();
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

//public slots:
void LoginWindow::launch()
{
	volatile uint autoLoginStatus = checkAutoLogin();
	switch (autoLoginStatus)
	{
	case 1:
	{
		emit properLogin();
		delete this;
		break;
	}
	case 2:
		informUser(U"该用户已在线");
		break;
	case 3:
		this->show();
	}
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


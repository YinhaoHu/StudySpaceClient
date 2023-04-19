#include"comchatpage.hpp"

#include"data/runtime_datamanager.hpp"
#include"../../widget/tipwindow.hpp"
#include"../../../standard.hpp"
#include"../../../net/netcontroller.hpp"
#include"../../../net/net.hpp"

#include<thread>

#include<QtGui/qkeysequence.h>
#include<QtWidgets/qscrollbar.h>
#include<QtWidgets/qwidget.h>

using namespace std;
using namespace Page;

extern net::NetController* netController;//From mainwindow.cpp
extern net::Client* clientNet;//From driver.cpp
extern standard::dataStruct::UserData userData;
extern QSharedPointer<data::Runtime_DataManager> runtime_dataManager;

//private:
void ComChat::setupView() {
	view.setupUi(this);
	resize(this->parentWidget()->size());

	tipWindow = new TipWindow;

	messageWidget = new MessageWidget(32, 600, 10, view.recvMsgBlockContent);
	messageWidget->setParent(view.recvMsgBlockContent);
}

void ComChat::setupDelegate() {
	QObject::connect(view.sendMsgButton, SIGNAL(pressed()), 
		this, SLOT(addSentMsg()),Qt::QueuedConnection);
}

//public:
ComChat::ComChat(QWidget* parent)
	:QWidget(parent),selfProfile(new QPixmap(standard::file::selfProfile))
{
	close();
	setParent(parent);

	setupView();
	setupDelegate();
}

void ComChat::setupNetController()
{
	connect(netController, SIGNAL(comChatRecv_update()),
		this, SLOT(comChatRecv_update()));
}

void ComChat::keyPressEvent(QKeyEvent* event)
{
	if (event->matches(QKeySequence::InsertParagraphSeparator))
		view.sendMsgButton->click();
}

void ComChat::addRecvMsg(QString&& msg, QString&& username, QPixmap&& profile)
{
	QScrollBar* scrollBar;
	
	messageWidget->addMsg(std::move(msg), 
		std::move(profile), std::move(username), Message::Receiver);

	scrollBar = view.recvMsgBlock->verticalScrollBar();
	scrollBar->setValue(scrollBar->maximum());
}

//public slots:
void ComChat::addSentMsg() {
	QString msg = view.sendMsgBlock->toPlainText();
	QScrollBar* scrollBar;

	//Check
	if (msg.isEmpty())
	{
		tipWindow->inform(U"请输入内容");
		return;
	}
	if (msg.size() > 512)
	{
		tipWindow->inform(U"最多可以发送\n512个字符");
		return;
	}

	//local display
	messageWidget->addMsg(std::move(msg), 
		runtime_dataManager->get_personalInfo_smallProfile(),
		runtime_dataManager->get_personalInfo_username(), 
		Message::Sender);
	view.sendMsgBlock->clear();

	scrollBar = view.recvMsgBlock->verticalScrollBar();
	scrollBar->setValue(scrollBar->maximum());

	//Send to server
	QString cmd, userid, sendMsgBuffer;
	char32_t* sendMsg;

	cmd = QString::fromStdU32String(U"COMCHATSEND");
	userid = userData.selfID;
	sendMsgBuffer = cmd + " " + userid + " " + msg;

	sendMsg = new char32_t[net::sockMsgLen];
	memset(sendMsg, 0, net::sockMsgBytes);
	memcpy(sendMsg, sendMsgBuffer.toStdU32String().c_str(), sendMsgBuffer.size() * sizeof(char32_t));

	clientNet->sendMsg(sendMsg);
}

void ComChat::comChatRecv_update() 
{
	addRecvMsg(std::move(netController->comChatRecv_data.msg),
		std::move(netController->comChatRecv_data.sendername),
		std::move(netController->comChatRecv_data.senderProfile));
}
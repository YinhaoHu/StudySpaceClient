#include"chatpage.hpp"

#include"../../widget/tipwindow.hpp"
#include"../../../standard.hpp"
#include"../../../net/netcontroller.hpp"
#include"../../../net/net.hpp"

#include<thread>

#include<QtGui/qkeysequence.h>
#include<QtWidgets/qscrollbar.h>
#include<QtWidgets/qwidget.h>

using namespace std;

extern net::NetController* netController;//From mainwindow.cpp
extern net::Client* clientNet;//From driver.cpp
extern standard::dataStruct::UserData userData;


//private:
void ChatPage::setupView() {
	view.setupUi(this);
	resize(this->parentWidget()->size());

	tipWindow = new TipWindow;

	messageWidget = new MessageWidget(32, 600, 10, view.recvMsgBlockContent);
	messageWidget->setParent(view.recvMsgBlockContent);
}

void ChatPage::setupDelegate() {
	QObject::connect(view.sendMsgButton, SIGNAL(pressed()), 
		this, SLOT(addSentMsg()),Qt::QueuedConnection);
}

//public:
ChatPage::ChatPage(QWidget* parent)
	:QWidget(parent)
{
	close();
	setParent(parent);

	setupView();
	setupDelegate();

}

void ChatPage::setupNetController()
{
	connect(netController, SIGNAL(comChatRecv_update()),
		this, SLOT(comChatRecv_update()));
}

void ChatPage::keyPressEvent(QKeyEvent* event)
{
	if (event->matches(QKeySequence::InsertParagraphSeparator))
		view.sendMsgButton->click();
}

void ChatPage::setSelfProfile(QPixmap* profilePixmap)
{
	selfProfile = profilePixmap;
}

void ChatPage::addRecvMsg(QString& msg, QString& username, QPixmap& profile)
{
	QScrollBar* scrollBar;
	
	messageWidget->addMsg(msg, profile, username, 0);

	scrollBar = view.recvMsgBlock->verticalScrollBar();
	scrollBar->setValue(scrollBar->maximum());
}

//public slots:
void ChatPage::addSentMsg() {
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
	messageWidget->addMsg(msg, *selfProfile,
		userData.selfUsername, 1);
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

void ChatPage::comChatRecv_update() 
{
	addRecvMsg(netController->comChatRecv_data.msg,
		netController->comChatRecv_data.sendername,
		netController->comChatRecv_data.senderProfile);
}
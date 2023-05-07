#include"chatpage.hpp"
#include"model/widget/chat/privatedialogwidget.hpp"

#include"inc_data/extern_data.hpp"
#include"inc_net/extern_net.hpp"
#include"inc_tip/extern_tipwindow.hpp"

#include<qkeysequence.h>

using namespace std;
using namespace net;

static auto& NC = netController;
static auto& NC_LOCK = NetControllerMutexLock;

// private

void ChatPage::setupView()
{
	view.setupUi(this);

	view.messageListWidget->close();
	view.titleLabel->close();
	view.inputBlock->close();
	view.sendMsgButton->close();

	close();
}

void ChatPage::setupDelegate()const
{
	connect(view.sendMsgButton, SIGNAL(pressed()),
		this, SLOT(sendMessage_slot()));
}

void ChatPage::setupNetController()const
{
	connect(NC, &NetController::privateChatRecvMsg_signal,
		this, &ChatPage::recvMessage_slot);
	connect(netController, &net::NetController::removeFriend_signal,
		this, &ChatPage::privateDialog_removeOne_netSlot);
}

void ChatPage::setupLocalData()
{
	auto& ld = local_dataManager;

	auto entries = ld->getPrivateChatData();
	auto userIDStr = QString::number(ld->getUserID());

	for (auto& otherID : entries.keys())//Every chat object.
	{
		for (auto& entry : entries[otherID])//every msg
		{
			auto& sender = entry.first;
			auto& content = entry.second;

			if (sender == userIDStr)
				this->privateDialog_addRightMsg_slot(otherID.toULong(), content);
			else
				this->privateDialog_addLeftMsg_slot(otherID.toULong(), content);
		}
	}
}

bool ChatPage::checkInputValid()const
{
	auto input = view.inputBlock->toPlainText();
	bool res = true;

	if (input.length() > 512)
	{
		tipWindow->inform(std::move(QString("消息长度不能超过512字符，尝试分段发送")));
		res = false;
	}
	else if (input.isEmpty())
	{
		tipWindow->inform(std::move(QString("请输入消息内容")));
		res = false;
	}

	return res;
}

void ChatPage::privateDialog_makeOne(uint otherID) 
{
	(*privateDialogs)[otherID] = new PrivateDialogWidget(this, otherID);
	auto& newDialogWidget = (*privateDialogs)[otherID];
	newDialogWidget->resize(this->view.messageListWidget->size());
	newDialogWidget->setParent(view.messageListWidget);
}

void ChatPage::privateDialog_removeOne_netSlot(QString otherID)
{
	this->privateDialog_removeOne(otherID.toULong());
}

void ChatPage::privateDialog_removeOne(uint otherID)
{
	auto widget = privateDialogs->value(otherID);
	if (currentDialog_ID == otherID)
	{
		currentDialog_ID = this->invalidDialog_ID;
		currentDialog_widget->close();
		currentDialog_widget = nullptr;

		view.titleLabel->clear();
	}

	runtime_dataManager->remove_friendsInfo_usernameObject(otherID, 
		view.titleLabel);
	privateDialogs->remove(otherID);
	delete widget;
}

void ChatPage::keyPressEvent(QKeyEvent* _event)
{
	if(_event->matches(QKeySequence::InsertParagraphSeparator))
	{
		this->sendMessage_slot();
	}
}

// public

ChatPage::ChatPage(QWidget* _parent)
	:QWidget(_parent), currentDialog_widget(nullptr),
	privateDialogs(new QHash<uint, PrivateDialogWidget*>)
{
	setupView();
	setupDelegate();
}

ChatPage::~ChatPage()
{
	for (auto ptr : privateDialogs->values())
		delete ptr;

	delete privateDialogs;
}

uint ChatPage::getCuurentDialogID()const
{
	return currentDialog_ID;
}

// private slots:

void ChatPage::sendMessage_slot()
{
	if (!checkInputValid())
		return;

	if (currentDialog_ID == 0)
	{
		tipWindow->inform(std::move(QString("请选择聊天对象")));
		return;
	}

	auto data = view.inputBlock->toPlainText();

	privateDialog_addRightMsg_slot(currentDialog_ID, data);
	local_dataManager->appendPrivateChatData(QString::number(currentDialog_ID),
		QString::number(local_dataManager->getUserID()), data);

	view.inputBlock->clear();
	{
		unique_lock lock(netMutexLock);
		clientNet->easySend_Request(std::move(QString("PRIVATE_CHAT_SEND")),
			std::move(local_dataManager->getUserID()));
		clientNet->easySend_U32String(std::move(QString::number(currentDialog_ID)));
		clientNet->easySend_U32String(std::move(data));
	}
}

// public slots:

void ChatPage::recvMessage_slot(uint otherID, QString msg)
{
	QString allID = QString::number(otherID);

	privateDialog_addLeftMsg_slot(otherID, msg);
	local_dataManager->appendPrivateChatData(allID, allID, msg);
}

void ChatPage::privateDialog_addLeftMsg_slot(uint otherID, QString msg)
{
	if (!privateDialogs->contains(otherID))
	{
		privateDialog_makeOne(otherID);
	}
	auto dialog = privateDialogs->value(otherID);
	dialog->addLeftMessage_slot(otherID , msg);
}

void ChatPage::privateDialog_addRightMsg_slot(uint otherID, QString msg)
{
	if(!privateDialogs->contains(otherID))
	{
		privateDialog_makeOne(otherID);
	}
	auto dialog = privateDialogs->value(otherID);
	dialog->addRightMessage_slot( msg);
}


void ChatPage::privateDialog_open_slot(uint otherID)
{
	if ((*privateDialogs)[otherID] == nullptr)
	{
		privateDialog_makeOne(otherID);
	}

	view.messageListWidget->show();
	view.titleLabel->show();
	view.inputBlock->show();
	view.sendMsgButton->show();

	
	if(currentDialog_widget != nullptr)
	{
		currentDialog_widget->close();
		runtime_dataManager->remove_friendsInfo_usernameObject(otherID, view.titleLabel);
	}

	currentDialog_ID = otherID;
	currentDialog_widget = privateDialogs->value(otherID);

	runtime_dataManager->add_friendsInfo_usernameObject(otherID, view.titleLabel);
	currentDialog_widget->show();
	currentDialog_widget->raise();
}

void ChatPage::privateDialog_remove_slot(uint otherID)
{
	
	this->privateDialog_removeOne(otherID);
}
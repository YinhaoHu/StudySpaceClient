#include"notificationitem.hpp"

#include"inc_net/extern_net.hpp"
#include"inc_data/extern_data.hpp"

#include<mutex>

using namespace std;

void NotificationItem::setupView()
{
	view.setupUi(this);

	switch (type)
	{
	case NotificationItem::FriendRequest:
	{
		view.addFriendWidget->show();
		view.pureNoticeWidget->close();

		QString userinfo("[");
		userinfo.append(*userName);
		userinfo.push_back(']');
		userinfo.append(*userID);

		view.userinfoLabel->setText(userinfo);
		view.messageLabel->setText(std::move(QString("请求添加你为好友")));
		break;
	}
	case NotificationItem::PureNotice:
		view.pureNoticeWidget->show();
		view.addFriendWidget->close();

		view.noticeLabel->setText(*pureNotification);
		break;
	}
}

void NotificationItem::setupDelegate()const
{
	switch (type)
	{
		case NotificationItem::FriendRequest:
			connect(view.yesButton, SIGNAL(pressed()), this, SLOT(addFriend_sendAccept()));
			connect(view.noButton, SIGNAL(pressed()), this, SLOT(addFriend_sendReject()));
			break;
		case NotificationItem::PureNotice:
			connect(view.confirmButton, SIGNAL(pressed()), this,SLOT(pureNotice_confirmSlot()));
			break;
	}
}

NotificationItem::NotificationItem(QListWidget* parent, uint idnum,
	QString&& username, QString&& userid,Type _type)
	:QWidget(parent), userName(new QString(username)),
	userID(new QString(userid)), userIDNum(idnum),type(_type)
{
	setupView();
	setupDelegate();
}

NotificationItem::NotificationItem(QListWidget* parent, QString&& msg,uint noticeID,
	Type _type):QWidget(parent), pureNotification(new QString(msg)),
	pureNoticeID(noticeID), type(_type)
{
	setupView();
	setupDelegate();
}

NotificationItem::~NotificationItem()
{
	switch (type)
	{
	case NotificationItem::FriendRequest:
		delete userName;
		delete userID;
		break;
	case NotificationItem::PureNotice:
		delete pureNotification;
		break;
	}
	
}

void NotificationItem::addFriend_sendAccept()
{
	{
		unique_lock lock(netMutexLock);
		auto request = new QString("ADDFRIEND_CONFIRM ");
		request->append(QString::number(local_dataManager->getUserID()));

		clientNet->easySend_Msg(std::move(*request));
		clientNet->easySend_U32String(std::move(QString("ACCEPT")));
		clientNet->easySend_U32String(std::move(QString(*userID)));

		//GET FRIEND DATA
		auto request_2 = new QString("GET_NEW_FRIEND_INFO ");
		request_2->append(QString::number(local_dataManager->getUserID()));

		clientNet->easySend_Msg(std::move(*request_2));
		clientNet->easySend_U32String(std::move(*userID));
	}
	
	emit deleteMe(userIDNum);
}

void NotificationItem::addFriend_sendReject()
{
	{
		unique_lock lock(netMutexLock);
		auto request = new QString("ADDFRIEND_CONFIRM ");
		request->append(QString::number(local_dataManager->getUserID()));

		clientNet->easySend_Msg(std::move(*request));
		clientNet->easySend_U32String(std::move(QString("REJECT")));
		clientNet->easySend_U32String(std::move(QString(*userID)));
	}
	emit deleteMe(userIDNum);
}

void NotificationItem::pureNotice_confirmSlot()
{
	emit deleteMe(pureNoticeID);
}
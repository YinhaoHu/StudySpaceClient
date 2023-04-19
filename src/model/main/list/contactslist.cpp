#include"contactslist.hpp"
#include"inc_data/extern_data.hpp"
#include"inc_net/extern_net.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"model/widget/social/friendlistitem.hpp"
#include"model/main/page/contactspage.hpp"

using namespace std;

void ContactsList::makeFirendList() 
{
	for (auto userID : items->keys())
	{
		auto newItem = items->value(userID);
		auto newFriendListItem = friendListItems->value(userID);

		newItem->setSizeHint(QSize(newFriendListItem->itemWidth, newFriendListItem->itemHeight));
		view.friendsList->addItem(newItem);
		view.friendsList->setItemWidget(newItem, newFriendListItem);
	}
}

ContactsList::ContactsList(QWidget* parent = nullptr)
	:QWidget(parent), inited(false),
	relatedPage(nullptr),
	friendListItems(new QHash<unsigned int, FriendListItem*>),
	items(new QHash<unsigned int, QListWidgetItem*>),
	notificationQItems(new QHash<unsigned int, QListWidgetItem*>),
	notificationListItems(new QHash<unsigned int, NotificationItem*>),
	pureNoticeCount(0)
{
	setupView();
	setupDelegate();
	setupNetController();

	curList = view.friendsList;
}

ContactsList::~ContactsList()
{
	delete items;
	delete friendListItems;
	delete relatedPage;
}

void ContactsList::setupNetController()const
{
	{
		unique_lock lock(netMutexLock);

		auto request = new QString("GET_NOTIFICATION ");
		request->append(QString::number(local_dataManager->getUserID()));
		clientNet->easySend_Msg(std::move(*request));
		delete request;
	}

	connect(netController, SIGNAL(getFriendList_update_signal()),
		this, SLOT(getFriendList_update_slot()), Qt::QueuedConnection);
	
	connect(netController, &net::NetController::addFriend_Notice_signal,
		this, &ContactsList::getNotification_addFriend_slot);

	connect(netController, &net::NetController::addFriend_accepted_signal,
		this, &ContactsList::addFriend_accepted_slot);

	connect(netController, &net::NetController::addFriend_rejected_signal,
		this, &ContactsList::addFriend_rejected_slot);

	connect(netController, &net::NetController::addFriend_makeListItem_signal,
		this, &ContactsList::addFriend_makeListItem_slot);

	connect(netController, &net::NetController::removeFriend_signal,
		this, &ContactsList::removeFriend_slot);

	connect(netController, &net::NetController::pureNotice_signal,
		this, &ContactsList::getNotification_pure_slot);
}

void ContactsList::setupDelegate()const
{
	connect(view.friendsList, &QListWidget::itemClicked, this, &ContactsList::passValueToPage);
	connect(view.checkNotificationButton, SIGNAL(pressed()), this, SLOT(listChanged()));
	connect(view.checkNotificationButton, SIGNAL(pressed()), view.noticeNewLabel, SLOT(close()));
}

//Send the related data to the data manager
void ContactsList::setupRuntimeData()const
{
	auto& dataSource = netController->getFriendList_data;
	for (size_t i = 0; i <dataSource.id->size();++i)
	{
		auto id = (*dataSource.id)[i].toUInt();
		runtime_dataManager->update_friendsInfo_bigProfileObject(id);
		runtime_dataManager->update_friendsInfo_smallProfileObject(id);
		runtime_dataManager->update_friendsInfo_usernameObject(id,
			std::move(QString((*dataSource.name)[i])));
		runtime_dataManager->update_friendsInfo_onlineStatusObject(id,
			std::move(QString((*dataSource.onlineStatus)[i])));
		runtime_dataManager->update_friendsInfo_introObjects(id,
			std::move(QString((*dataSource.intro)[i])));
	}
}

void ContactsList::setupView()
{
	view.setupUi(this);
	view.notificationList->close();
	view.noticeNewLabel->close();
	this->close();
}

void ContactsList::setRelatedPage(ContactsPage* page)
{
	relatedPage = page; 

	connect(this, &ContactsList::sendID, relatedPage, &ContactsPage::viewFriend);
	connect(view.addFriendButton, SIGNAL(pressed()), relatedPage, SLOT(addFriend()));
}

void ContactsList::init()
{
	/*
		Send Rules:
			1) Prog: GETFRIENDSLIST USERID
		
		Recv Rules:
			Get from the net controller.
	*/
	if(inited == false)
	{
		auto idNum = local_dataManager->getUserID();
		QString* requestProg(new QString);

		requestProg->append("GETFRIENDSLIST ");
		requestProg->append(QString::number(idNum));

		clientNet->easySend_Msg(std::move(*requestProg));

		delete requestProg;
		inited = true;
	}
}

void ContactsList::passValueToPage(QListWidgetItem* whichItem)
{
	auto userID = items->key(whichItem);

	emit this->sendID(userID);
}

void ContactsList::getFriendList_update_slot()
{
	{
		unique_lock lock(NetControllerMutexLock);

		setupRuntimeData();
		for (auto& id : *netController->getFriendList_data.id)
		{
			items->insert(id.toULong(), new QListWidgetItem(view.friendsList));
			friendListItems->insert(id.toULong(), new FriendListItem(id.toULong(), view.friendsList));
		}


	}
	makeFirendList();
}

void ContactsList::listChanged()
{
	curList->close();

	if (curList == view.notificationList)
	{
		view.checkNotificationButton->setText(QString("查看通知"));
		curList = view.friendsList;
	}
	else
	{
		view.checkNotificationButton->setText(QString("查看好友"));
		curList = view.notificationList;
	}

	curList->show();
}

void ContactsList::getNotification_addFriend_slot(QString name,QString userID)
{
	auto idNum = userID.toULong();
	auto newItem = new NotificationItem(view.notificationList,
		userID.toULong(), std::move(name), std::move(userID));
	auto newQItem = new QListWidgetItem(view.notificationList);

	notificationQItems->insert(idNum, newQItem);
	notificationListItems->insert(idNum, newItem);

	newQItem->setSizeHint(QSize(newItem->itemWidth, newItem->itemHeight));
	view.notificationList->addItem(newQItem);
	view.notificationList->setItemWidget(newQItem, newItem);
	view.noticeNewLabel->show();

	connect(newItem, &NotificationItem::deleteMe,
		this, &ContactsList::deleteNotification);
}

void ContactsList::getNotification_pure_slot(QString notice)
{
	auto curID = pureNoticeCount;
	auto newItem = new NotificationItem(view.notificationList,std::move(notice),curID);
	auto newQItem = new QListWidgetItem(view.notificationList);

	notificationQItems->insert(curID, newQItem);
	notificationListItems->insert(curID, newItem);

	newQItem->setSizeHint(QSize(newItem->itemWidth, newItem->itemHeight));
	view.notificationList->addItem(newQItem);
	view.notificationList->setItemWidget(newQItem, newItem);
	view.noticeNewLabel->show();

	connect(newItem, &NotificationItem::deleteMe,
		this, &ContactsList::deleteNotification);

	++pureNoticeCount;
}

void ContactsList::deleteNotification(uint id)
{
	auto oldQItem= notificationQItems->value(id);
	auto oldItem= notificationListItems->value(id);

	notificationQItems->remove(id);
	notificationListItems->remove(id);

	delete oldQItem;
	delete oldItem;
}

void ContactsList::addFriend_accepted_slot(QString fromID)
{
	{
		unique_lock lock(netMutexLock);
		auto request = new QString("GET_NEW_FRIEND_INFO ");
		request->append(QString::number(local_dataManager->getUserID()));
		clientNet->easySend_Msg(std::move(*request));
		clientNet->easySend_U32String(std::move(fromID));
		delete request;
	}
	getNotification_pure_slot(fromID.append(" 同意添加你为好友"));
}

void ContactsList::addFriend_rejected_slot(QString fromID)
{
	getNotification_pure_slot(fromID.append(" 拒绝添加你为好友"));
}

void ContactsList::addFriend_makeListItem_slot(uint id)
{
	auto newFriendItem = new FriendListItem(id, view.friendsList);
	auto newItem = new QListWidgetItem(view.friendsList);

	friendListItems->insert(id, newFriendItem);
	items->insert(id, newItem);

	newItem->setSizeHint(QSize(newFriendItem->itemWidth, newFriendItem->itemHeight));
	view.friendsList->addItem(newItem);
	view.friendsList->setItemWidget(newItem, newFriendItem);
}

void ContactsList::removeFriend_slot(QString id)
{
	auto idNum = id.toULong();

	auto removedItem_row = view.friendsList->row(items->value(idNum));

	view.friendsList->takeItem(removedItem_row);
	view.friendsList->removeItemWidget(items->value(idNum));

	friendListItems->remove(idNum);
	items->remove(idNum);
	
	relatedPage->showDefault();

	delete friendListItems->value(idNum); 
	delete items->value(idNum);
}
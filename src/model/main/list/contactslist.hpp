#pragma once

#include"view/main/list/ui_contactslist.hpp"

#include"model/widget/social/notificationitem.hpp"

#include<vector>

#include<qlistwidget.h>
#include<qpushbutton.h>

class ContactsPage;
class FriendListItem;

class ContactsList:public QWidget
{
	Q_OBJECT

private:
	Ui::contactslist view;

	bool inited;
	QListWidget* curList;
	ContactsPage* relatedPage;
	QHash<unsigned int,FriendListItem*>* friendListItems;
	QHash<unsigned int, QListWidgetItem*>* items;

	QHash<unsigned int, QListWidgetItem*>* notificationQItems;
	QHash<unsigned int, NotificationItem*>* notificationListItems;
	uint pureNoticeCount;

	void makeFirendList();

public:
	ContactsList(QWidget* parent);
	~ContactsList();

public:
	void setupNetController() const ;
	void setupDelegate()const;
	void setupView();

	void setRelatedPage(ContactsPage*page);

signals:
	void sendID(unsigned int userID);

public slots:
	void init();

	void passValueToPage(QListWidgetItem* whichItem);
	void getFriendList_update_slot();
	void getNotification_addFriend_slot(QString name, QString userID);
	void getNotification_pure_slot(QString notice);

	void addFriend_accepted_slot(QString id);
	void addFriend_rejected_slot(QString id);
	void addFriend_makeListItem_slot(uint friendID);

	void deleteNotification(uint id);
	void listChanged();

	void removeFriend_slot(QString id);
};
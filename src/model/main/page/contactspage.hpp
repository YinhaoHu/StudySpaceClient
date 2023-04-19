#pragma once

#include"view/main/page/ui_contactspage.hpp"
#include"model/widget/social/addfriendform.hpp"
#include<qwidget.h>


class ContactsPage : public QWidget
{
	Q_OBJECT

private:
	Ui::ContactsPage view;
	AddFriendForm* addFriendForm;

	unsigned int userID;

public:
	ContactsPage(QWidget* parent);
	~ContactsPage();

	void setupView();
	void setupDelegate()const;

private slots:
	void removeFriend_Request();

public slots:
	void showDefault();
	void viewFriend(unsigned int newID);
	void addFriend();
};
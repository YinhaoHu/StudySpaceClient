#pragma once

#include"contactspage.hpp"
#include"inc_data/extern_data.hpp"
#include"inc_net/extern_net.hpp"

ContactsPage::ContactsPage(QWidget* parent = nullptr)
	:QWidget(parent), userID(0), 
	addFriendForm(new AddFriendForm)
{
	setupView();
	setupDelegate();
}

ContactsPage::~ContactsPage()
{

}

void ContactsPage::setupView()
{
	view.setupUi(this);
	addFriendForm->setParent(view.addFriendWidget);
	view.viewFriendWidget->close();
	view.addFriendWidget->close();
	close();
}

void ContactsPage::setupDelegate()const
{
	connect(view.deleteFriendButton, SIGNAL(pressed()),
		this, SLOT(removeFriend_Request()));
}

void ContactsPage::addFriend()
{
	view.viewFriendWidget->close();
	view.addFriendWidget->show();
}

void ContactsPage::removeFriend_Request()
{
	{
		std::unique_lock lock(netMutexLock);

		clientNet->easySend_Request(std::move(QString("REQUEST_REMOVE_FRIEND")),
			local_dataManager->getUserID());
		clientNet->easySend_U32String(std::move(QString::number(userID)));
	}
}

void ContactsPage::viewFriend(unsigned int newID)
{
	if(userID != 0)
	{
		runtime_dataManager->remove_friendsInfo_bigProfileObject(userID, view.profileLabel);
		runtime_dataManager->remove_friendsInfo_usernameObject(userID, view.nameLabel);
		runtime_dataManager->remove_friendsInfo_introObject(userID, view.introLabel);
	}

	runtime_dataManager->add_friendsInfo_bigProfileObject(newID, view.profileLabel);
	runtime_dataManager->add_friendsInfo_usernameObject(newID, view.nameLabel);
	runtime_dataManager->add_friendsInfo_introObject(newID, view.introLabel);
	view.IDLabel->setText(QString::number(newID));

	view.addFriendWidget->close();
	view.viewFriendWidget->show();

	userID = newID;
}

void ContactsPage::showDefault()
{
	view.addFriendWidget->close();
	view.viewFriendWidget->close();
}
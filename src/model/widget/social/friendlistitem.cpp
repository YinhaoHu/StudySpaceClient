#include"friendlistitem.hpp"

#include"data/runtime_datamanager.hpp"

extern QSharedPointer<data::Runtime_DataManager> runtime_dataManager;

void FriendListItem::setupView()
{
	view.setupUi(this);
}


FriendListItem::FriendListItem(unsigned int _userID, QListWidget* _parent = nullptr)
	:userID(_userID), QWidget(_parent)
{
	setupView();
	setupRuntimeData();
}
	
FriendListItem::~FriendListItem()
{
	runtime_dataManager->remove_friendsInfo_samllProfileObject(this->userID,this->view.profileLabel);
	runtime_dataManager->remove_friendsInfo_onlineStatusObject(this->userID,this->view.statusLabel);
	runtime_dataManager->remove_friendsInfo_usernameObject(this->userID,this->view.nameLabel);
}

QLabel*  FriendListItem::getProfileLabel()const
{
	return this->view.profileLabel;
}

QLabel* FriendListItem::getNameLabel()const
{
	return this->view.nameLabel;
}

QLabel* FriendListItem::getOnlineStatusLabel()const
{
	return this->view.statusLabel;
}

void FriendListItem::setupRuntimeData()const
{
	runtime_dataManager->add_friendsInfo_smallProfileObject(this->userID, this->view.profileLabel);
	runtime_dataManager->add_friendsInfo_onlineStatusObject(this->userID, this->view.statusLabel);
	runtime_dataManager->add_friendsInfo_usernameObject(this->userID, this->view.nameLabel);
}

#include"privatechatlistitem.hpp"

#include"inc_data/extern_data.hpp"

PrivateChatListItemWidget::PrivateChatListItemWidget(QListWidget* _parent, uint _userID)
	:QWidget(_parent), userID(_userID)
{
	setupView();
	setupRuntimeData();
}

PrivateChatListItemWidget::~PrivateChatListItemWidget()
{
	runtime_dataManager->remove_friendsInfo_samllProfileObject(userID, view.profileLabel);
	runtime_dataManager->remove_friendsInfo_usernameObject(userID, view.nameLabel);
}

void PrivateChatListItemWidget::setupView()
{
	view.setupUi(this);
	view.tipLabel->close();

	this->widgetHeight = view.background->height();
	this->widgetWidth = view.background->width();
}

void PrivateChatListItemWidget::setupRuntimeData() const
{
	runtime_dataManager->add_friendsInfo_smallProfileObject(userID, view.profileLabel);
	runtime_dataManager->add_friendsInfo_usernameObject(userID, view.nameLabel);
}

uint PrivateChatListItemWidget::getUserID()const
{
	return this->userID;
}

void PrivateChatListItemWidget::noticeNew()
{
	view.tipLabel->show();
}

void PrivateChatListItemWidget::disnoticeNew()
{
	view.tipLabel->close();
}
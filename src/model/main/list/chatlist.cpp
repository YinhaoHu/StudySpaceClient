#include"chatlist.hpp"

#include"model/widget/chat/privatechatlistitem.hpp"
#include"inc_net/extern_net.hpp"
#include"inc_data/extern_data.hpp"

ChatList::ChatList(QWidget* parent)
	:QWidget(parent), dialogItems(new QHash<uint, QListWidgetItem*>),
	privateDialogWidgets(new QHash<uint, PrivateChatListItemWidget*>)
{
	setupView();
	setupDelegate();
}

ChatList::~ChatList()
{
	delete dialogItems;
	delete privateDialogWidgets;
}

// Section: setup

void ChatList::setupView()
{
	view.setupUi(this);
}

void ChatList::setupNetController()const
{
	connect(netController, &net::NetController::privateChatNotice_signal,
		this, &ChatList::getPrivateChatNotice_netSlot);

	connect(netController, &net::NetController::removeFriend_signal,
		this, &ChatList::removeDialogItem);
}

void ChatList::setupDelegate()const
{
	connect(view.dialogListWidget, &QListWidget::itemPressed,
		this, &ChatList::forwardItemInfo_slot);
}

void ChatList::setRealatedPage(ChatPage* page)
{
	relatedPage = page;
}

void ChatList::setupLocalData()
{
	// Performance is a little bad as chatlist & page use this function
	// repeatedly.

	auto& ld = local_dataManager;
	auto entries = ld->getPrivateChatData();
	for (auto& otherID : entries.keys())//Every chat object.
	{
		this->addDialogItem(otherID.toULong());
	}
}

// Serction : signal & slot

void ChatList::forwardItemInfo_slot(QListWidgetItem* whichItem)
{
	auto otherID = dialogItems->key(whichItem);
	auto widget = privateDialogWidgets->value(otherID);

	widget->disnoticeNew();
	this->relatedPage->show();

	emit privateChat_noticeOpenPage_signal(otherID);
}

void ChatList::getPrivateChatNotice_netSlot(uint userID)
{
	if(!dialogItems->contains(userID))
	{
		addDialogItem(userID);
	}
	
	if (this->relatedPage->getCuurentDialogID() != userID)
	{
		auto widget = privateDialogWidgets->value(userID);
		widget->noticeNew();
	}
}

void ChatList::jumpToDialog_slot(uint userID)
{
	if ( dialogItems->contains(userID) == false)
	{
		addDialogItem(userID);
	}
	forwardItemInfo_slot(dialogItems->value(userID));
}

void ChatList::addDialogItem(uint otherID)
{
	auto widget = new PrivateChatListItemWidget(view.dialogListWidget, otherID);
	auto item = new QListWidgetItem(view.dialogListWidget);

	dialogItems->insert(otherID, item);
	privateDialogWidgets->insert(otherID, widget);

	item->setSizeHint(QSize(widget->widgetWidth, widget->widgetHeight));
	view.dialogListWidget->addItem(item);
	view.dialogListWidget->setItemWidget(item, widget);
}

void ChatList::removeDialogItem(QString otherIDstr)
{
	auto otherID = otherIDstr.toULong();
	auto item = dialogItems->value(otherID);
	auto widget = privateDialogWidgets->value(otherID);

	auto itemRow = view.dialogListWidget->row(item);

	this->view.dialogListWidget->takeItem(itemRow);
	
	dialogItems->remove(otherID);
	this->privateDialogWidgets->remove(otherID);
	local_dataManager->deletePrivateChatDataItem(otherIDstr);

	delete item;
	delete widget;

	emit this->privateChat_noticeRemovePage_signal(otherID);
}
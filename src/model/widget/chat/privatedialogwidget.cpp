#include"model/widget/chat/privatedialogwidget.hpp"
#include"model/widget/chat/messageblock.hpp"
#include"inc_data/extern_data.hpp"

#include<qsizepolicy.h>
#include<qscrollbar.h>

auto& LDM = local_dataManager;

void PrivateDialogWidget::makeItemWidget(uint id, QString&& msg, MessageBlock::Type _type)
{
	auto widget = new MessageBlock(this,std::move(msg), id, _type);
	auto item = new QListWidgetItem(this);

	messageItems->push_back(item);
	messageWidgets->push_back(widget);

	item->setSizeHint(QSize(widget->getWidth(), widget->height()));
	accumulatedHeight += widget->height();
	if (accumulatedHeight > 500)
	{
		auto t = this->height();
		auto ts = this->minimumHeight();
	}
	item->setFlags(Qt::NoItemFlags);
	this->setSelectionMode(QAbstractItemView::NoSelection);
	this->addItem(item);
	this->setItemWidget(item, widget);
	this->scrollToBottom();
}

PrivateDialogWidget::PrivateDialogWidget(QWidget* parent, uint _otherID)
	:QListWidget(parent), messageItems(new QVarLengthArray<QListWidgetItem*>),
	messageWidgets(new QVarLengthArray<MessageBlock*>), otherID(_otherID),
	accumulatedHeight(0)
{
	this->setVerticalScrollMode(ScrollPerPixel);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

PrivateDialogWidget::~PrivateDialogWidget()
{
	delete messageItems;
	delete messageWidgets;
}

void PrivateDialogWidget::addRightMessage_slot(QString msg)
{
	makeItemWidget(LDM->getUserID(), std::move(msg), MessageBlock::Right);
}

void PrivateDialogWidget::addLeftMessage_slot(uint userID, QString msg)
{
	makeItemWidget(userID, std::move(msg), MessageBlock::Left);
}
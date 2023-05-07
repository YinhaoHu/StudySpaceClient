#pragma once

#include"view/widget/chat/ui_chatlistitem.hpp"

#include<qlistwidget.h>

class PrivateChatListItemWidget: public QWidget
{
	Q_OBJECT
private:
	Ui::ChatListItemWidget view;
	uint userID;

public:
	 uint widgetHeight;
	 uint widgetWidth;
	

	PrivateChatListItemWidget(QListWidget* parent, uint userID);
	~PrivateChatListItemWidget();

	void setupView();
	void setupRuntimeData() const;

	uint getUserID()const;

public slots:

	void noticeNew();
	void disnoticeNew();
};
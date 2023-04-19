#pragma once
#include"view/widget/social/ui_friendlistitem.hpp"

#include<qlistwidget.h>
#include<qlabel.h>

class FriendListItem : public QWidget
{
private:
	Ui::FriendListItem view;

	unsigned int userID;

	void setupView();

public:
	static const unsigned int itemHeight = 38;
	static const unsigned int itemWidth = 200;

public:
	FriendListItem(unsigned int id,QListWidget* parent);
	~FriendListItem();

public:
	QLabel* getProfileLabel()const;
	QLabel* getNameLabel()const;
	QLabel* getOnlineStatusLabel()const;

	void setupRuntimeData()const;

};
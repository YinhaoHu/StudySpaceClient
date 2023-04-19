#pragma once

#include"view/widget/social/ui_addfriendform.hpp"

#include<qwidget.h>

class AddFriendForm:public QWidget
{
	Q_OBJECT

private:
	Ui::AddFriendForm view;

	void setupView();
	void setupDelegate()const;
	void setupNetController()const;

	void requestAddFriend()const;

public:
	AddFriendForm(QWidget* parent = nullptr );

private slots:
	void checkInput();

public slots:
	void addFriend_Check_slot(QString msg);
};
#pragma once

#include"view/main/page/ui_chatpage.hpp"
#include"model/widget/chat/privatedialogwidget.hpp"
#include<qlistwidget.h>
#include<qhash>

class ChatPage : public QWidget
{
	Q_OBJECT
friend class MainWindow;

private:
	Ui::ChatPage view;
	QListWidget* currentDialog_widget;
	uint currentDialog_ID = 0;
	QHash<uint, PrivateDialogWidget*>* privateDialogs;

	const uint invalidDialog_ID = 0;

	void setupView();
	void setupNetController()const;
	void setupDelegate()const;
	void setupLocalData();

	bool checkInputValid()const;

	void privateDialog_makeOne(uint id);
	void privateDialog_removeOne(uint otherID);
	void privateDialog_removeOne_netSlot(QString otherID);
	void keyPressEvent(QKeyEvent* e);

public:
	ChatPage(QWidget* _parent);
	~ChatPage();

	uint getCuurentDialogID()const;

private slots:
	void sendMessage_slot(); 
public slots:
	void recvMessage_slot(uint otherID, QString msg);

public slots:
	void privateDialog_open_slot(uint otherID);
	void privateDialog_addLeftMsg_slot(uint otherID, QString msg);
	void privateDialog_addRightMsg_slot(uint otherID, QString msg);

	void privateDialog_remove_slot(uint otherID);
};
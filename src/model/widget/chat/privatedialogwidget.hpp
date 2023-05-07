#pragma once

#include"model/widget/chat/messageblock.hpp"
#include"model/widget/chat/privatechatlistitem.hpp"
#include<qlistwidget.h>
#include<qvarlengtharray.h>


class PrivateDialogWidget: public QListWidget
{
	Q_OBJECT
private:
	uint otherID;
	uint accumulatedHeight;

	QVarLengthArray<QListWidgetItem*>* messageItems;
	QVarLengthArray<MessageBlock*>* messageWidgets;

	/*	POSSIBLY 
	void loadLocalData();
	void updateLocalData();
	*/
	void makeItemWidget(uint _otherID,QString&& msg,MessageBlock::Type _type);
public:
	PrivateDialogWidget(QWidget* parent, uint otherID);
	~PrivateDialogWidget();

public slots:
	void addRightMessage_slot(QString msg);
	void addLeftMessage_slot(uint userID, QString msg);
};
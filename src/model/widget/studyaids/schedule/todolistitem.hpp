#pragma once

#include"view/widget/studyaids/schedule/todolistitem.hpp"
#include<qlistwidget.h>

class TodoListItem : public QWidget
{
	Q_OBJECT
private:
	Ui::todolistitem view;
	uint index;
	QString task;
	bool finished_flag;

	void setup();

public:
	TodoListItem(QListWidget* parent, QString&& content, uint _index, bool _finishedFlag = false);
	TodoListItem(TodoListItem& rhs);
	~TodoListItem();

	void setID(uint newID);

	bool isFinished()const;
	QString getTask()const;

private slots:
	void makeFinished();
	void forwardFinished();

signals:
	void finished(uint index);
};

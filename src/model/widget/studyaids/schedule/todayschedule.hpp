#pragma once

#define _TODAYSCHEDULE_

#include"model/widget/studyaids/schedule/todolistitem.hpp"
#include"view/widget/studyaids/schedule/todayschedule.hpp"

#include<qlistwidget.h>
#include<qvarlengtharray.h>
#include<qpair.h>

class TodayScheduleWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::todayScheduleWidget view;

	QVarLengthArray<QListWidgetItem*> items;
	QVarLengthArray<TodoListItem*> widgets;

	void setupView();
	void setupDelegate();

	void loadTasks();
	void storeTasks()const;

	void addTaskItem(QString& content, bool finished);
	void removeTaskItem(uint id);
	void moveTaskItemToBottom(qsizetype id);

private slots:
	void addTask_entry();
	void addTask_handler(QString& task);

	void switchToView_addTaskEntry();
	void switchToView_inputTask();

public:
	TodayScheduleWidget(QWidget* parent);
	~TodayScheduleWidget();

	void initDataManager();
};
#include"todayschedule.hpp"

#include"inc_data/studyaids/smartextern_todayschedule.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"inc_data/extern_data.hpp"
#include<qdatetime.h>

/*
				Note 
	For the first develop , I did not consider much 
	the performance of the code in order to have a 
	faster developing.

	For optimization, pay attention to these members:
		-> moveTaskItemToBottom
		-> storeTasks
*/

TodayScheduleWidget::TodayScheduleWidget(QWidget* parent)
	:QWidget(parent)
{
	setupView();;
	setupDelegate();
}

TodayScheduleWidget::~TodayScheduleWidget() 
{
	storeTasks();
	delete todayScheduleDataManager;
}

void TodayScheduleWidget::setupView()
{
	QDateTime localTime(QDateTime::currentDateTimeUtc().toLocalTime());
	QDate date(localTime.date());
	auto m = date.month();
	auto d = date.day();

	view.setupUi(this);
	view.listWidget->setWindowFlag(Qt::FramelessWindowHint);
	view.listWidget->setSelectionMode(QAbstractItemView::NoSelection);
	view.todolistwidget->setWindowFlag(Qt::FramelessWindowHint);

	view.titleBar->setText("我的一天");
	view.subtitleBar->setText(QString("  %1月 %2日").arg(m).arg(d));
}

void TodayScheduleWidget::setupDelegate()
{
	connect(view.addTaskEntryButton, SIGNAL(pressed()),
		this, SLOT(switchToView_inputTask()));
	connect(view.addTaskButton, SIGNAL(pressed()),
		this, SLOT(addTask_entry()));
}

void TodayScheduleWidget::loadTasks()
{
	using DM = data::TodayScheduleDataManager;
	auto& dm = *todayScheduleDataManager;
	qsizetype n = dm.size();

	for (qsizetype i = 0; i < n; ++i)
	{
		auto item = dm.getItem(i);
		auto& s = item[DM::ItemIndex::Status];
		auto& c = item[DM::ItemIndex::Task];

		if (s == dm.status.unfinished)
			addTaskItem(c, false);
		else
			addTaskItem(c, true);
	}
}

void TodayScheduleWidget::storeTasks()const
{
	auto& dm = *todayScheduleDataManager;

	uint id = 0;
	for (auto& widget : widgets)
	{
		QString status = widget->isFinished() ? 
			dm.status.finished : dm.status.unfinished;
		dm.update(id, status, widget->getTask());
		id++;
	}
}

void TodayScheduleWidget::addTaskItem(QString& content, bool finished)
{
	auto &dm = *todayScheduleDataManager;
	auto& lw = *view.listWidget;
	auto item = new QListWidgetItem;
	auto widget = new TodoListItem(view.listWidget, std::move(content),
		items.size(), finished);

	item->setSizeHint(widget->size());
	item->setFlags(Qt::NoItemFlags);
	if (finished == false)
		lw.insertItem(0, item);
	else
		lw.insertItem(lw.count(), item);
	lw.setItemWidget(item, widget);

	items.push_back(item);
	widgets.push_back(widget);

	connect(widget, &TodoListItem::finished, 
		this, &TodayScheduleWidget::removeTaskItem);
}

void TodayScheduleWidget::removeTaskItem(uint id)
{
	moveTaskItemToBottom(id);
}

void TodayScheduleWidget::moveTaskItemToBottom(qsizetype id)
{
	
	auto old = widgets[id];
	auto row = view.listWidget->row(items[id]);

	auto newWidget = new TodoListItem(*old);
	auto newItem = new QListWidgetItem(view.listWidget);

	view.listWidget->takeItem(row);
	
	items.erase(items.begin() + id);
	widgets.erase(widgets.begin() + id);
	
	items.push_back(newItem);
	widgets.push_back(newWidget);

	for (qsizetype i = 0; i < items.size(); ++i)
	{
		widgets[i]->setID(i);
	}

	newItem->setSizeHint(newWidget->size());
	view.listWidget->addItem(newItem);
	view.listWidget->setItemWidget(newItem, newWidget);
}

void TodayScheduleWidget::addTask_entry()
{
	auto task = view.addTaskInput->text();

	if (task.isEmpty())
		tipWindow->inform("请输入内容");
	else
	{
		view.addTaskInput->clear();
		addTask_handler(task);
	}
}

void TodayScheduleWidget::addTask_handler(QString& task)
{
	auto& dm = *todayScheduleDataManager;
	addTaskItem(task, false);
	dm.addItem(dm.status.unfinished, task);
	switchToView_addTaskEntry();
}

void TodayScheduleWidget::switchToView_addTaskEntry()
{
	view.addTaskEntryButton->show();
	view.addTaskInput->close();
	view.addTaskButton->close();
}

void TodayScheduleWidget::switchToView_inputTask()
{
	view.addTaskEntryButton->close();
	view.addTaskInput->show();
	view.addTaskButton->show();
}

void TodayScheduleWidget::initDataManager()
{
	todayScheduleDataManager = 
		new data::TodayScheduleDataManager(local_dataManager->getUserID());

	loadTasks();
}
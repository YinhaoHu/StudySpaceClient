#include"schedulewidget.hpp"

ScheduleWidget::ScheduleWidget(QWidget* parent)
	:QWidget(parent)
{
	setupView();
	setupDelegate();

	setupWidgets();
}

ScheduleWidget::~ScheduleWidget() {}

void ScheduleWidget::setupDelegate()
{

}

void ScheduleWidget::setupView()
{
	view.setupUi(this);
	close();
}

void ScheduleWidget::setupWidgets()
{
	widgets = {
		new TodayScheduleWidget(view.contentwidget)
	};

	connect(view.todayschedulebutton, SIGNAL(pressed()),
		widgets.todaySchedule, SLOT(show()));
}

void ScheduleWidget::initDataManager()
{
	widgets.todaySchedule->initDataManager();
}
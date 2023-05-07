#pragma once
#include"view/widget/studyaids/schedule/schedulewidget.hpp"
#include"todayschedule.hpp"

class ScheduleWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::scheduleWidget view;

	struct {
		TodayScheduleWidget* todaySchedule;
	}widgets;

	void setupDelegate();
	void setupView();

	void setupWidgets();
public:
	ScheduleWidget(QWidget* parent);
	~ScheduleWidget();

	void initDataManager();
};
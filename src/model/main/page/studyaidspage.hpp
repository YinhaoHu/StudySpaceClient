#pragma once

#include"view/main/page/ui_studyaidspage.hpp"
#include"model/widget/studyaids/focus/focuswidget.hpp"
#include"model/widget/studyaids/schedule/schedulewidget.hpp"

class StudyAidsPage : public QWidget
{
	Q_OBJECT

public:
	enum WidgetOptions{Focus, Course,  Target, Schedule};

private:
	Ui::studyaidspage view;


	QWidget* currentWidget;
	struct {
		FocusWidget* focusWidget;
		ScheduleWidget* schedulWidget;
	}widgets;

	void setupView();
	void setupWidgets();

public:
	StudyAidsPage(QWidget *parent);
	~StudyAidsPage();

	void setupLocalDatamanager();

public slots:
	void switchToWidget(WidgetOptions option);
};
#pragma once

#include"view/widget/studyaids/focus/startfocus.hpp"
#include"focusfeedback.hpp"

class StartFocusWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::StartFocus view;

	struct {
		int totalMinutes;
		int leftMinutes;
		QTimer* timer;
	}focusTime;
	FocusFeedBack* feedBackWidget;

	void setupView();
	void setupDelegate();

	void setFocusOn();
	void setFocusOff();

	void openTimeControl();
public:
	StartFocusWidget(QWidget* parent);
	~StartFocusWidget();


private slots:
	void endFocus_handler();
	void enterFocus_handler();
	void pauseFocus_handler();
	void continueFocus_handler();

	void endFocus_dataHandler(FocusFeedBack::Rating);

	void minuteMinused_handler();

signals:
	void dataUpdated();
};
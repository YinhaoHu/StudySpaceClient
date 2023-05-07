#pragma once

#include"view/widget/studyaids/focus/focusfeedback.hpp"

class FocusFeedBack :public QWidget
{
	Q_OBJECT
public:
	enum Rating {Bad =1 , Mid, Good};

private:
	Ui::focusfeedback view;

	void setupView()
	{
		view.setupUi(this);
		close();
	}

	void setupDelegate()
	{
		connect(view.badButton, &QPushButton::pressed,
			this, [=]() {emit rated(Bad); });
		connect(view.midButton, &QPushButton::pressed,
			this, [=]() {emit rated(Mid); });
		connect(view.goodButton, &QPushButton::pressed,
			this, [=]() {emit rated(Good); });

		connect(view.badButton, SIGNAL(pressed()),
			this, SLOT(close()));
		connect(view.midButton, SIGNAL(pressed()),
			this, SLOT(close()));
		connect(view.goodButton, SIGNAL(pressed()),
			this, SLOT(close()));

	}

public:
	FocusFeedBack(QWidget* parent)
		:QWidget(parent)
	{
		setWindowFlag(Qt::FramelessWindowHint);
		setupView();
		setupDelegate();
	}

	~FocusFeedBack()
	{

	}

signals:
	void rated(Rating rating);
};
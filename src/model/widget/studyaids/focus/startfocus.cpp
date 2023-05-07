#include"startfocus.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"inc_data/extern_data.hpp"
#include"inc_data/studyaids/smartextern_focus.hpp"

#include<qtimer.h>

using namespace std;
// 60000 is correct, other value for debug
static const int MSECPERMIN = 60;
// Constructor & Destructor 

StartFocusWidget::StartFocusWidget(QWidget* parent)
	:QWidget(parent), focusTime{0,0, new QTimer},
	feedBackWidget(new FocusFeedBack(this))
{
	setupView();
	setupDelegate();
}

StartFocusWidget::~StartFocusWidget()
{
}

// Setup part

void StartFocusWidget::setupDelegate()
{
	connect(view.startButton, SIGNAL(pressed()),
		this, SLOT(enterFocus_handler()));
	connect(view.controlButton, SIGNAL(pressed()),
		this, SLOT(pauseFocus_handler()));
	connect(view.endButton, SIGNAL(pressed()),
		this, SLOT(endFocus_handler()));

	connect(feedBackWidget, &FocusFeedBack::rated,
		this, &StartFocusWidget::endFocus_dataHandler);
}

void StartFocusWidget::setupView()
{
	view.setupUi(this);
	close();

	setFocusOff();
}

// Mode Change Section

void StartFocusWidget::setFocusOn()
{
	view.timeInfoSetWidget->close();
	view.startButton->close();
	
	view.timeInfoDisplayWidget->show();
	view.controlWidget->show();

	view.timeBar->setMaximum(focusTime.leftMinutes);
	view.timeBar->setValue(focusTime.leftMinutes);
	view.timeBar->setMinimum(0);
}

void StartFocusWidget::setFocusOff()
{
	view.timeInfoDisplayWidget->close();
	view.controlWidget->close();

	view.timeInfoSetWidget->show();
	view.startButton->show();

	view.timeBar->setValue(0);
}

void StartFocusWidget::openTimeControl()
{
	auto& t = *focusTime.timer;

	int hr = focusTime.leftMinutes / 60;
	int min = focusTime.leftMinutes - hr * 60;

	view.hourLCD->display(hr);
	view.minuteLCD->display(min);

	t.start(focusTime.leftMinutes * MSECPERMIN);
	t.setInterval(MSECPERMIN * 1);
	connect(&t, SIGNAL(timeout()), this, SLOT(minuteMinused_handler()));
}

// Handlers

void StartFocusWidget::endFocus_dataHandler(FocusFeedBack::Rating rating)
{
	auto& dm = *focusDataManager;

	dm.addItem(std::move(QString::number(focusTime.totalMinutes)), 
		QString::number(rating));
	emit dataUpdated();
}

void StartFocusWidget::endFocus_handler()
{
	//Include set mode & feedback & store the data./
	auto& t = focusTime;

	t.timer->stop();
	t.leftMinutes = 0;
	setFocusOff();
	
	auto fx = width()*0.5 - feedBackWidget->width()*0.5;
	auto fy = height() * 0.5 - feedBackWidget->height() * 0.5;
	feedBackWidget->show();
	feedBackWidget->move(fx, fy);
	feedBackWidget->raise();
	if(this->isHidden())
		tipWindow->remind("此次专注活动已结束，快去看看吧!");
}

void StartFocusWidget::enterFocus_handler()
{
	auto focus_time = view.timeInfoSetInput->text().split(':');
	auto left_hour = focus_time[0].toULong();

	focusTime.totalMinutes = focus_time[1].toULong() + left_hour * 60;
	focusTime.leftMinutes = focusTime.totalMinutes;

	if (focusTime.leftMinutes < 25)
	{
		tipWindow->inform("专注时间不小于25分钟哟~");
	}
	else if (feedBackWidget->isHidden() == false)
	{
		tipWindow->inform("上一次的专注活动评分还没完成哦~");
	}
	else
	{
		setFocusOn();
		openTimeControl();
	}
}

void StartFocusWidget::pauseFocus_handler()
{
	focusTime.timer->stop();
	view.controlButton->setText("继续");

	disconnect(view.controlButton, SIGNAL(pressed()),
		this, SLOT(pauseFocus_handler()));

	connect(view.controlButton, SIGNAL(pressed()),
		this, SLOT(continueFocus_handler()));
}

void StartFocusWidget::continueFocus_handler()
{
	focusTime.timer->start(focusTime.leftMinutes * MSECPERMIN);
	focusTime.timer->setInterval(MSECPERMIN * 1);
	view.controlButton->setText("暂停");

	disconnect(view.controlButton, SIGNAL(pressed()),
		this, SLOT(continueFocus_handler()));

	connect(view.controlButton, SIGNAL(pressed()),
		this, SLOT(pauseFocus_handler()));
}

void StartFocusWidget::minuteMinused_handler()
{
	auto& m = focusTime.leftMinutes;
	--m;

	if (m == 0)
	{
		this->endFocus_handler();
	}
	else
	{
		auto hour = m / 60;
		auto minute = m - hour * 60;

		view.minuteLCD->display(minute);
		view.hourLCD->display(hour);
		view.timeBar->setValue(m);
	}
}

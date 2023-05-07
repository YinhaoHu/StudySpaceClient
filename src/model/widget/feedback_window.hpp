#pragma once

#include"view/widget/ui_feedback.hpp"

class FeedBackWindow : public QWidget
{
	Q_OBJECT

private:
	Ui::FeedBackWindow view;
	
public:
	FeedBackWindow();
	~FeedBackWindow();

public slots:
	void sendFeedBack();
};
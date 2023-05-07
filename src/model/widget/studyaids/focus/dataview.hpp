#pragma once

#include"view/widget/studyaids/focus/dataview.hpp"
#include<qwidget.h>

class DataViewWidget : public QWidget
{
	Q_OBJECT

private:
	Ui::DataView view;

	void setupView();

	void initView_list();
	void initView_form();
	void initView_chart();

public:
	DataViewWidget(QWidget* parent);
	~DataViewWidget();

	void initView();

public slots:
	void updateView();
};
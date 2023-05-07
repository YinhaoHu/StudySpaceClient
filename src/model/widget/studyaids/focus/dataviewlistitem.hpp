#pragma once

#include"view/widget/studyaids/focus/dataviewlistitem.hpp"
#include"qlistwidget.h"

class DataViewListItem : public QWidget
{
	 Q_OBJECT
private:
	Ui::DataViewListItem view;

	void setupView()
	{
		view.setupUi(this);
	}

public:
	DataViewListItem(QListWidget*parent,qsizetype index, QString&&year, QString&& month, 
		QString&& day,QString&& rating, QString&&duration):
		QWidget(parent)
	{
		setupView();

		QString date = QString("%1年%2月%3日").arg(year).arg(month).arg(day);

		view.indexLabel->setText(QString::number(index));
		view.durationLabel->setText(QString("%1 mins").arg(duration));
		view.dateLabel->setText(date);
		view.ratingLabel->setText(QString("%1 分").arg(rating));
	}
	~DataViewListItem() {}
};
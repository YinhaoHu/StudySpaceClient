#include<qlineseries.h>
#include<qchartview.h>
#include<qchart.h>
#include<qpainter.h>
#include<qvalueaxis.h>

#include"dataview.hpp"
#include"dataviewlistitem.hpp"
#include"inc_data/studyaids/smartextern_focus.hpp"

using namespace data;

DataViewWidget::DataViewWidget(QWidget* parent)
	:QWidget(parent)
{
	setupView();
}

DataViewWidget::~DataViewWidget() {}

void DataViewWidget::initView_list()
{
	qsizetype n = focusDataManager->size();

	for (qsizetype i = 0; i < n; ++i)
	{
		qsizetype index = i + 1;
		auto item = focusDataManager->getItem(i);

		QString duration = item[FocusDataManager::ItemIndex::Duration];
		QString year = item[FocusDataManager::ItemIndex::Year];
		QString month = item[FocusDataManager::ItemIndex::Month];
		QString day = item[FocusDataManager::ItemIndex::Day];
		QString rating = item[FocusDataManager::ItemIndex::Rating];

		auto listItem = new QListWidgetItem(view.listWidget);
		auto listItemWidget = new DataViewListItem(view.listWidget, index,
			std::move(year),std::move(month),std::move(day),
			std::move(rating),std::move(duration));

		auto wh = listItemWidget->height();
		auto ww = listItemWidget->width();

		listItem->setSizeHint(QSize(ww,wh));
		view.listWidget->addItem(listItem);
		view.listWidget->setItemWidget(listItem, listItemWidget);
	}
}

void DataViewWidget::initView_form()
{
	//Dataitems: total time, total count, avrg time, averg score
	auto& fd = *focusDataManager;
	qsizetype n = fd.size();

	uint totalScore = 0, totalTime = 0;
	double avgScore = 0, avgTime = 0;
	for (qsizetype i = 0; i < n; ++i)
	{
		auto item = fd.getItem(i);

		totalScore += item[FocusDataManager::ItemIndex::Rating].toULong();
		totalTime += item[FocusDataManager::ItemIndex::Duration].toULong();
	}
	avgScore = (double)totalScore / n;
	avgTime = (double)totalTime / n;

	view.totalCountDisplay->setText(QString::number(n));
	view.totalDurationDisplay->setText(QString("%1 mins").arg(QString::number(totalTime)));
	view.averageScoreDisplay->setText(QString::number(avgScore,103,2));
	view.averageDurationDisplay->setText(QString("%1 mins").arg(QString::number(avgTime, 103, 4)));
}

void DataViewWidget::initView_chart()
{
	qsizetype n = focusDataManager->size();
	qsizetype i = (n > 14) ? n - 14 : 0, x = 1;;
	QLineSeries* lineseries = new QLineSeries;
	
	for (i; i < n; ++i,++x)
	{
		auto score = focusDataManager->getItem(i)[FocusDataManager::ItemIndex::Rating].toULong();
		lineseries->append(x, score);
	}

	auto chart = new QChart;

	auto ax = new QValueAxis;
	auto ay = new QValueAxis;

	chart->addSeries(lineseries);
	chart->createDefaultAxes();
	chart->legend()->hide();
	chart->setAxisX(ax);
	chart->setAxisY(ay);

	ax->setTickCount(14 > n ? n : 14);
	ax->setLabelFormat("%i");
	ax->setTitleText("次序");

	ay->setRange(1, 3);
	ay->setTickCount(3);
	ay->setTitleText("得分");
	ay->setLabelFormat("%i");

	lineseries->attachAxis(ax);
	lineseries->attachAxis(ay);

	chart->setTitle(QString("近 %1 次专注情况").arg(14 > n ? n : 14));

	QChartView* chartView = new QChartView(view.chartView);

	chartView->setChart(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	chartView->resize(view.chartView->size());
	chartView->show();
}


void DataViewWidget::initView()
{
	initView_list();
	initView_form();
	initView_chart();
}

void DataViewWidget::updateView()
{
	// For faster developing, we choose code in this way,
	// although it has bad perfomance.
	view.listWidget->clear();
	initView();
}

void DataViewWidget::setupView()
{
	view.setupUi(this);
	close();
}
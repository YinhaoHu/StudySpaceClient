#pragma once

#include<qstring.h>
#include<qjsonarray.h>

namespace data
{
	class TodayScheduleDataManager;
}

class data::TodayScheduleDataManager
{
public:
	enum ItemIndex {Status, Task};

	struct {
		QString finished = "finished";
		QString unfinished = "unfinished";
	}status;

private:
	uint userID;
	QString filename;
	QString dir;
	QJsonArray jsonarray;

	void saveData();
	void loadData();
	void setupInfo();

public:
	TodayScheduleDataManager(uint _userID);
	~TodayScheduleDataManager();

	void update(uint id, QString status, QString content);
	qsizetype size()const;
	QStringList getItem(qsizetype index);
	void addItem(QString status, QString task);
};
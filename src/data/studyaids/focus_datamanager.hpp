#pragma once

#include"data/local_datamanager.hpp"

#include<qstring.h>

namespace data
{
	class FocusDataManager;
}

class data::FocusDataManager
{
private:
	QJsonArray* ja;
	QString* filename;
public:
	enum ItemIndex{Duration, Rating, Year, Month, Day};

	FocusDataManager();
	~FocusDataManager();

	void addItem(QString&& durationMins, QString&& rating);
	QStringList getItem(qsizetype index);

	qsizetype size()const;
};
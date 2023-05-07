#include"focus_datamanager.hpp"
#include"inc_data/extern_data.hpp"
#include"standard.hpp"
#include<filesystem>

#include<qfile.h>
#include<qjsonarray.h>
#include<qjsonobject.h>
#include<qjsondocument.h>

using namespace data;
using namespace std;

/*
* About File
*	userdata/userid/focusdata.json
* 
* 
* About Data
	Json: Array

	Item format example:
	{
		"duration": "25"
		"rating": "3"
		"year": "2023"
		"month": "1"
		"day": "3"
	}
*/

FocusDataManager::FocusDataManager()
	:ja(new QJsonArray),filename(new QString)
{
	using standard::file::focusdata;
	using standard::dir::root;

	QString dirname = QString("%1/%2").arg(root).arg(local_dataManager->getUserID());
	*filename = QString("%1/%2").arg(dirname).arg(focusdata);

	if (filesystem::exists(filename->toStdString()) == false)
	{
		filesystem::create_directory(dirname.toStdString());
		QFile fi(*filename);
		fi.open(QIODeviceBase::WriteOnly);
		//Write new data.
		QJsonDocument jo;
		QJsonArray ja;
		jo.setArray(ja);
		fi.write(jo.toJson());
		fi.close();
	}

	QFile f(*filename);
	f.open(QIODeviceBase::ReadOnly);

	QJsonDocument jd(QJsonDocument::fromJson(f.readAll()));
	*ja = jd.array();
	f.close();
}

FocusDataManager::~FocusDataManager()
{
	QFile f(*filename);
	f.open(QIODeviceBase::WriteOnly);

	QJsonDocument jd;
	jd.setArray(*ja);
	f.write(jd.toJson());
	f.close();

	delete filename;
	delete ja;
}

void FocusDataManager::addItem(QString&& durationMins, QString&& rating)
{
	QDateTime localTime(QDateTime::currentDateTimeUtc().toLocalTime());
	QDate date(localTime.date());
	
	QJsonObject jo{
		{"duration",durationMins},
		{"rating",rating },
		{"year", QString::number(date.year())},
		{"month",  QString::number(date.month())},
		{"day",  QString::number(date.day())}
	};

	ja->push_back(jo);
}

QStringList FocusDataManager::getItem(qsizetype index)
{
	auto item = ja->at(index);

	return QStringList{
		item["duration"].toString(),
		item["rating"].toString(),
		item["year"].toString(),
		item["month"].toString(),
		item["day"].toString()
	};
}

qsizetype FocusDataManager::size()const
{
	return ja->size();
}
#include"todayschedule_datamanager.hpp"
#include"standard.hpp"

#include<qjsonarray.h>
#include<qjsondocument.h>
#include<qjsonobject.h>
#include<qfile.h>

#include<filesystem>

using namespace std;
using namespace data;
/*
*		Convention 
* Filename
*	userdata/userid/schedule/today.json
* 
* JsonType
*	json array
* 
* Json array item: json object
*  format
*		{
*			"status": ""	(finished, unfinished)
*			"content": ""
*		}
* 
*/
TodayScheduleDataManager::TodayScheduleDataManager(uint _userID)
	:userID(_userID)
{
	setupInfo();
	loadData();
}

TodayScheduleDataManager::~TodayScheduleDataManager() 
{
	saveData();
}


void TodayScheduleDataManager::saveData()
{
	QFile file(filename);
	file.open(QIODeviceBase::WriteOnly);
	QJsonDocument jd;
	jd.setArray(jsonarray);
	file.write(jd.toJson());
	file.close();
}

void TodayScheduleDataManager::loadData()
{
	if (filesystem::exists(filename.toStdString()) == false)
		filesystem::create_directory(dir.toStdString());
	else
	{
		QFile file(filename);
		file.open(QIODeviceBase::ReadOnly);

		QJsonDocument jd(QJsonDocument::fromJson(file.readAll()));
		jsonarray = jd.array();

		file.close();
	}
}

void TodayScheduleDataManager::setupInfo()
{
	using namespace standard;
	
	QDateTime localTime(QDateTime::currentDateTimeUtc().toLocalTime());
	QDate date(localTime.date());
	auto y = date.year();
	auto m = date.month();
	auto d = date.day();

	dir = QString("%1/%2/%3").arg(dir::root).arg(userID).arg(dir::sub1_schedule);
	filename = QString("%1/%2%3%4%5").arg(dir).arg(y).arg(m).arg(d).
		arg(file::todayScheduleData);
}

qsizetype TodayScheduleDataManager::size()const
{
	return jsonarray.size();
}

void TodayScheduleDataManager::update(uint id, QString status, QString content)
{
	auto oldObj = this->jsonarray[id].toObject();
	
	oldObj["status"] = status;
	oldObj["content"] = content;

	this->jsonarray[id] = oldObj;
}

QStringList TodayScheduleDataManager::getItem(qsizetype index)
{
	auto obj = jsonarray[index].toObject();

	auto status = obj["status"].toString();
	auto content = obj["content"].toString();
	return QStringList{status, content};
}

void TodayScheduleDataManager::addItem(QString status, QString task)
{
	QJsonObject jo;
	jo["status"] = status;
	jo["content"] = task;

	jsonarray.push_back(jo);
}
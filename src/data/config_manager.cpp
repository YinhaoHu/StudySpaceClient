#include"config_manager.hpp"

#include"standard.hpp"
#include<filesystem>

#include<qdir>
#include<qfile>
#include<qjsonobject.h>
#include<qjsonarray.h>
#include<qjsondocument.h>

using namespace std;
using namespace standard::file;

ConfigManager::ConfigManager()
	:netConfigInfoFilename(new QString(netConfigFile)),
	autoLoginInfoFilename(new QString(loginInfoFile)),
	netConfig(nullptr), autoLoginConfig(nullptr)
{
	load_netConfig();
	load_autoLoginConfig();
}

ConfigManager::~ConfigManager()
{
	save_autoLoginConfig();
	save_netConfig();

	delete netConfigInfoFilename;
	delete autoLoginInfoFilename;
}
// Private Helper

void ConfigManager::fix_netConfigFile()const
{
	QFile file(*this->netConfigInfoFilename);

	auto dirname = netConfigInfoFilename->split('/').front().toStdString();
	if (filesystem::exists(dirname) == false)
	{
		filesystem::create_directory(dirname);
	}

	file.open(QIODeviceBase::WriteOnly);
	
	QJsonObject jo;
	jo["IP"] = "";
	jo["PORT"] = "";

	QJsonDocument jd(jo);
	file.write(jd.toJson());
	file.close();
}

void ConfigManager::load_netConfig()
{
	QFile file(*this->netConfigInfoFilename);

	if (file.exists() == false)
		fix_netConfigFile();

	file.open(QIODeviceBase::ReadOnly);
	auto data = file.readAll();
	file.close();

	QJsonDocument jd(QJsonDocument::fromJson(data));
	netConfig = new QJsonObject(jd.object());

	if (!jd.isObject() || jd.isNull() || !netConfig->contains("IP") || !netConfig->contains("PORT"))
		fix_netConfigFile();

}

void ConfigManager::load_autoLoginConfig()
{
	QFile file(*this->autoLoginInfoFilename);
	file.open(QIODeviceBase::ReadOnly);
	auto data = file.readAll();

	QJsonDocument jd(QJsonDocument::fromJson(data));

	autoLoginConfig = new QJsonObject(jd.object());

	file.close();
}

void ConfigManager::save_netConfig()
{
	QFile file(*this->netConfigInfoFilename);
	file.open(QIODeviceBase::WriteOnly);
	
	QJsonDocument jd(*this->netConfig);

	file.write(jd.toJson());
	file.close();
	delete netConfig;
}

void ConfigManager::save_autoLoginConfig()
{
	QFile file(*this->autoLoginInfoFilename);

	file.open(QIODeviceBase::WriteOnly);

	QJsonDocument jd(*this->autoLoginConfig);

	file.write(jd.toJson());
	file.close();
	delete autoLoginConfig;
}


//	Public Inter face

QString ConfigManager::get_netConfigIP()
{
	return netConfig->value("IP").toString();
}
QString ConfigManager::get_netConfigPort()const
{
	return this->netConfig->value("PORT").toString();
}

QString ConfigManager::get_autoLoginExpireYear()const
{
	return (*this->autoLoginConfig)["EXPIRE_YEAR"].toString();
}

QString ConfigManager::get_autoLoginExpireMonth()const
{
	return (*this->autoLoginConfig)["EXPIRE_MONTH"].toString();
}

QString ConfigManager::get_autoLoginExpireDay()const
{
	return (*this->autoLoginConfig)["EXPIRE_DAY"].toString();
}

QString ConfigManager::get_autoLoginID()const
{
	return (*this->autoLoginConfig)["ID"].toString();
}

bool ConfigManager::valid_autoLoginData()const
{
	return this->autoLoginConfig->isEmpty() == true;
}

void ConfigManager::set_autoLoginID(QString&& id)
{
	(*this->autoLoginConfig)["ID"] = id;
}

void ConfigManager::set_autoLoginExpireYear(QString&& ey)
{
	(*this->autoLoginConfig)["EXPIRE_YEAR"] = ey;
}

void ConfigManager::set_autoLoginExpireMonth(QString&& em)
{
	(*this->autoLoginConfig)["EXPIRE_MONTH"] =em;
}

void ConfigManager::set_autoLoginExpireDay(QString&& ed)
{
	(*this->autoLoginConfig)["EXPIRE_DAY"] = ed;
}
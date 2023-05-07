#pragma once

#include<qobject.h>

class ConfigManager :public QObject
{
	Q_OBJECT

private:
	QString* netConfigInfoFilename;
	QString* autoLoginInfoFilename;

	QJsonObject* netConfig;
	QJsonObject* autoLoginConfig;

	void fix_netConfigFile()const;

private:
	void load_netConfig();
	void load_autoLoginConfig();

	void save_netConfig();
	void save_autoLoginConfig();

public:
	ConfigManager();
	~ConfigManager();

	QString get_netConfigIP();
	QString get_netConfigPort()const;

	QString get_autoLoginExpireYear()const;
	QString get_autoLoginExpireMonth()const;
	QString get_autoLoginExpireDay()const;
	QString get_autoLoginID()const;

	bool valid_autoLoginData()const;

	void set_autoLoginID(QString&& id);
	void set_autoLoginExpireYear(QString&& ey);
	void set_autoLoginExpireMonth(QString&& em);
	void set_autoLoginExpireDay(QString&& ed);
};
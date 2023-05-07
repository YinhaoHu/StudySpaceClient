#pragma once

#include<qobject.h>
#include<qstring.h>
#include<qlabel.h>
#include<qsharedpointer.h>
#include<qtextedit.h>

struct PersonalInfo;
struct FriendsInfo;

namespace data
{
	class Runtime_DataManager;
}

//Manage (update and get) the runtime data. 
class data::Runtime_DataManager: public QObject
{
	Q_OBJECT
private:
	QSharedPointer<PersonalInfo> personalInfo;
	QSharedPointer<FriendsInfo> friendsInfo;

public:
	Runtime_DataManager();
	~Runtime_DataManager();

public:
	//Personal info
	QString get_personalInfo_username();
	QPixmap get_personalInfo_bigProfile();
	QPixmap get_personalInfo_smallProfile();
	QString get_personalInfo_intro();

	void add_personalInfo_bigProfileObject(QLabel* object);
	void add_personalInfo_smallProfileObject(QLabel* object);
	void add_personalInfo_usernameObject(QLabel* object);
	void add_personalInfo_introObject(QTextEdit* object);

	void update_personalInfo_username(QString&& username);
	void update_personalInfo_profile();
	void update_personalInfo_intro(QString&& intro);

	void remove_personalInfo_smallProfileObject(QLabel *object);
	void remove_personalInfo_bigProfileObject(QLabel *object);
	void remove_personalInfo_usernameObject(QLabel *object);
	void remove_personalInfo_introObject(QTextEdit* object);

public:
	//Friends info
	void add_friendsInfo_onlineStatusObject(unsigned int id,QLabel* object);
	void add_friendsInfo_usernameObject(unsigned int id,QLabel* object);
	void add_friendsInfo_bigProfileObject(unsigned int id,QLabel* profile);
	void add_friendsInfo_smallProfileObject(unsigned int id,QLabel* profile);
	void add_friendsInfo_introObject(unsigned int id, QLabel* intro);

	void update_friendsInfo_onlineStatusObject(unsigned int id,QString&& status);
	void update_friendsInfo_usernameObject(unsigned int id,QString&& username);
	void update_friendsInfo_bigProfileObject(unsigned int id);
	void update_friendsInfo_smallProfileObject(unsigned int id);
	void update_friendsInfo_introObjects(unsigned int id, QString&& intro);

	void remove_friendsInfo_onlineStatusObject(unsigned int id, QLabel* object);
	void remove_friendsInfo_usernameObject(unsigned int id, QLabel* object);
	void remove_friendsInfo_bigProfileObject(unsigned int id, QLabel* object);
	void remove_friendsInfo_samllProfileObject(unsigned int id, QLabel* object);
	void remove_friendsInfo_introObject(unsigned int id, QLabel* object);

	QList<uint> get_friendsInfo_IDs();
};
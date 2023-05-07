#include"runtime_datamanager.hpp"
#include"local_datamanager.hpp"
#include"standard.hpp"

#include<qhash.h>
#include<qfile.h>
#include<qlabel.h>
#include<qsharedpointer.h>

struct PersonalInfo
{
	QString* userName;
	QPixmap* userSmallProfile;
	QPixmap* userBigProfile;
	QString* userIntro;

	QSet<QLabel*> *userBigProfile_objects;
	QSet<QLabel*>* userSmallProfile_objects;
	QSet<QLabel*> *userName_objects;
	QSet<QTextEdit*> *userIntro_objects;

	PersonalInfo() :
		userName(nullptr), userSmallProfile(nullptr), 
		userIntro(nullptr),userBigProfile(nullptr),
		userName_objects(new QSet<QLabel*>),
		userSmallProfile_objects(new QSet<QLabel*>),
		userBigProfile_objects(new QSet<QLabel*>),
		userIntro_objects(new QSet<QTextEdit*>)
	{}
};
struct FriendsInfo
{
	QHash<unsigned int, QString*>* usernameSet;
	QHash<unsigned int, QString*>* onlineStatusSet;
	QHash<unsigned int, QPixmap*>* bigProfileSet;
	QHash<unsigned int, QPixmap*>* smallProfileSet;
	QHash<unsigned int, QString*>* introSet;

	QHash<unsigned int, QSet<QLabel*>>* usernameObjects;
	QHash<unsigned int, QSet<QLabel*>>* smallProfileObjects;
	QHash<unsigned int, QSet<QLabel*>>* bigProfileObjects;
	QHash<unsigned int, QSet<QLabel*>>* onlineStatusObjects;
	QHash<unsigned int, QSet<QLabel*>>* introObjects;

	FriendsInfo() :
		usernameSet(new QHash<unsigned int, QString*>),
		onlineStatusSet(new QHash<unsigned int, QString*>),
		bigProfileSet(new QHash<unsigned int, QPixmap*>),
		smallProfileSet(new QHash<unsigned int, QPixmap*>),
		introSet(new QHash<unsigned int, QString*>),
		usernameObjects(new QHash<unsigned int, QSet<QLabel*>>),
		smallProfileObjects(new QHash<unsigned int, QSet<QLabel*>>),
		bigProfileObjects(new QHash<unsigned int, QSet<QLabel*>>),
		onlineStatusObjects(new QHash<unsigned int, QSet<QLabel*>>),
		introObjects(new QHash<unsigned int, QSet<QLabel*>>)
	{

	}
};

extern QSharedPointer<data::Local_DataManager> local_dataManager;

//This object should not deconstruct until the program ends.
data::Runtime_DataManager::~Runtime_DataManager() {}

//public
data::Runtime_DataManager::Runtime_DataManager()
	:personalInfo(QSharedPointer<PersonalInfo>(new PersonalInfo)),
	friendsInfo(QSharedPointer<FriendsInfo>(new FriendsInfo))
{

}

//Manage Personal info
QString data::Runtime_DataManager::
get_personalInfo_username()
{
	return *(this->personalInfo->userName);
}

QPixmap data::Runtime_DataManager::
get_personalInfo_bigProfile()
{
	return *(this->personalInfo->userBigProfile);
}

QPixmap data::Runtime_DataManager::
get_personalInfo_smallProfile()
{
	return *(this->personalInfo->userSmallProfile);
}

QString data::Runtime_DataManager::
get_personalInfo_intro()
{
	return *this->personalInfo->userIntro;
}

void data::Runtime_DataManager::
add_personalInfo_bigProfileObject(QLabel* object)
{
	object->setPixmap(*this->personalInfo->userBigProfile);
	this->personalInfo->userBigProfile_objects->insert(object);
}

void data::Runtime_DataManager::
add_personalInfo_smallProfileObject(QLabel* object)
{
	object->setPixmap(*this->personalInfo->userSmallProfile);
	this->personalInfo->userSmallProfile_objects->insert(object);
}

void data::Runtime_DataManager::
add_personalInfo_usernameObject(QLabel* object)
{
	object->setText(*this->personalInfo->userName);
	personalInfo->userName_objects->insert(object);
}

void data::Runtime_DataManager::
add_personalInfo_introObject(QTextEdit* object)
{
	object->setText(*this->personalInfo->userIntro);
	this->personalInfo->userIntro_objects->insert(object);
}

void data::Runtime_DataManager::
update_personalInfo_username(QString&& newName)
{
	if (personalInfo->userName == nullptr)
		personalInfo->userName = new QString(newName);
	else
		*(personalInfo->userName) = newName;

	for (auto object : *this->personalInfo->userName_objects)
	{
		object->setText(*(this->personalInfo->userName));
		object->update();
	}
}

void data::Runtime_DataManager::
update_personalInfo_profile()
{
	if (personalInfo->userSmallProfile != nullptr)
		delete personalInfo->userSmallProfile;
	personalInfo->userSmallProfile = new QPixmap(QPixmap( local_dataManager->getSelfProfile_filename()).scaled(32,32));
		
	if (personalInfo->userBigProfile != nullptr)
		delete personalInfo->userBigProfile;
	personalInfo->userBigProfile = new QPixmap(QPixmap( local_dataManager->getSelfProfile_filename()).scaled(100, 100));

	for (auto object : *personalInfo->userBigProfile_objects)
		object->setPixmap(*personalInfo->userBigProfile);
	
	for (auto object : *personalInfo->userSmallProfile_objects)
		object->setPixmap(*personalInfo->userSmallProfile);
}

void data::Runtime_DataManager::
update_personalInfo_intro(QString&& intro)
{
	if (personalInfo->userIntro == nullptr)
		personalInfo->userIntro = new QString(intro);
	else
		personalInfo->userIntro->swap(intro);

	for (QTextEdit* object : *(personalInfo->userIntro_objects) )
		object->setText(*(personalInfo->userIntro));
}

void data::Runtime_DataManager::remove_personalInfo_smallProfileObject(QLabel* object)
{
	personalInfo->userSmallProfile_objects->remove(object);
}

void data::Runtime_DataManager::remove_personalInfo_bigProfileObject(QLabel* object)
{
	personalInfo->userBigProfile_objects->remove(object);
}

void data::Runtime_DataManager::remove_personalInfo_usernameObject(QLabel* object)
{
	personalInfo->userName_objects->remove(object);
}

void data::Runtime_DataManager::remove_personalInfo_introObject(QTextEdit* object)
{
	personalInfo->userIntro_objects->remove(object);
}


//			************   Friends info section   ***************

//Part A: add
void data::Runtime_DataManager::
add_friendsInfo_onlineStatusObject(unsigned int id, QLabel* object)
{
	(*this->friendsInfo->onlineStatusObjects)[id].insert(object);

	object->setText(*((*(this->friendsInfo->onlineStatusSet))[id]));
}

void data::Runtime_DataManager::
add_friendsInfo_usernameObject(unsigned int id, QLabel* object)
{
	(*this->friendsInfo->usernameObjects)[id].insert(object);
	auto& data = *((*(this->friendsInfo->usernameSet))[id]);
	object->setText(data);
}

void data::Runtime_DataManager::
add_friendsInfo_bigProfileObject(unsigned int id, QLabel* object)
{
	(*this->friendsInfo->bigProfileObjects)[id].insert( object);

	object->setPixmap(*((*(this->friendsInfo->bigProfileSet))[id]));
}

void data::Runtime_DataManager::
add_friendsInfo_smallProfileObject(unsigned int id, QLabel* object)
{
	(*this->friendsInfo->smallProfileObjects)[id].insert(object);

	auto& data = *((*(this->friendsInfo->smallProfileSet))[id]);
	object->setPixmap(data);
}

void data::Runtime_DataManager::
add_friendsInfo_introObject(unsigned int id, QLabel* object)
{
	(*this->friendsInfo->introObjects)[id].insert(object);

	object->setText(*((*(this->friendsInfo->introSet))[id]));
}

//Part : update
void data::Runtime_DataManager::
update_friendsInfo_onlineStatusObject(unsigned int id, QString&& status)
{
	auto& set = *this->friendsInfo->onlineStatusSet;
	if (!set.contains(id))
		set[id] = new QString();
	auto& data = *(set)[id];
	data = status;

	for (auto object : (*this->friendsInfo->onlineStatusObjects)[id])
		object->setText(status);
}

void data::Runtime_DataManager::
update_friendsInfo_usernameObject(unsigned int id, QString&& username)
{
	auto& set = *this->friendsInfo->usernameSet;
	if (!set.contains(id))
		set[id] = new QString();
	auto& data = *(set)[id];
	data = username;

	for (auto object : (*this->friendsInfo->usernameObjects)[id])
		object->setText(username);
}

void data::Runtime_DataManager::
update_friendsInfo_bigProfileObject(unsigned int id)
{
	auto& set = (*this->friendsInfo->bigProfileSet);
	if (set.contains(id) == false)
		set[id] = new QPixmap();
	auto& data = *set[id];
	data = local_dataManager->getFriendProfile(id).scaled(
		standard::scale::bigProfileSideLen, standard::scale::bigProfileSideLen);

	for (auto object : this->friendsInfo->bigProfileObjects->value(id))
		object->setPixmap(data);
}

void data::Runtime_DataManager::
update_friendsInfo_smallProfileObject(unsigned int id)
{
	auto& set = (*this->friendsInfo->smallProfileSet);
	if (set.contains(id) == false)
		set[id] = new QPixmap();
	auto& data = *set[id];
	data = local_dataManager->getFriendProfile(id).scaled(
		standard::scale::smallProfileSideLen, standard::scale::smallProfileSideLen);

	for (auto object : this->friendsInfo->smallProfileObjects->value(id))
		object->setPixmap(data);
}

void data::Runtime_DataManager::
update_friendsInfo_introObjects(unsigned int id, QString&& intro)
{
	auto& set = *this->friendsInfo->introSet;
	if (!set.contains(id))
		set[id] = new QString();
	auto& data = *(set)[id];
	data = intro;

	for (auto object : (*this->friendsInfo->introObjects)[id])
		object->setText(intro);
}

QList<uint> data::Runtime_DataManager::get_friendsInfo_IDs()
{
	return friendsInfo->usernameSet->keys();
}

//Part : remove
void data::Runtime_DataManager::
remove_friendsInfo_onlineStatusObject(unsigned int id, QLabel* object)
{
	auto& fi = *this->friendsInfo;

	(*fi.onlineStatusObjects)[id].remove(object);
}

void data::Runtime_DataManager::
remove_friendsInfo_usernameObject(unsigned int id,QLabel* object)
{
	auto& fi = *this->friendsInfo;
	(*fi.usernameObjects)[id].remove(object);
}

void data::Runtime_DataManager::
remove_friendsInfo_samllProfileObject(unsigned int id, QLabel* object)
{
	auto& fi = *this->friendsInfo;

	(*fi.smallProfileObjects)[id].remove(object);
}

void data::Runtime_DataManager::
remove_friendsInfo_bigProfileObject(unsigned int id, QLabel* object)
{
	auto& fi = *this->friendsInfo;

	(*fi.bigProfileObjects)[id].remove(object);
}

void data::Runtime_DataManager::
remove_friendsInfo_introObject(unsigned int id, QLabel* object)
{
	auto& fi = *this->friendsInfo;

	(*fi.introObjects)[id].remove(object);
}
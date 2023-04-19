#include"local_datamanager.hpp"
#include"standard.hpp"

#include"qdir.h"

using namespace data;

/*
--------------------------------------------------
					RULES
--------------------------------------------------

	1 For the friend data file, we do not set the 
		extension name, e.g. if we create a new 
		file for storing the profile, we use the
		filename: 10001	instead of 10001.png or
		others like this.

	2	tempDirName: userdata/id/temp
		friendsProfile: userdata/id/friends/rofile
*/


data::Local_DataManager::
Local_DataManager() :
	tempFileDirName(new QString( standard::dir::root)),
	friendsProfileDirName(new QString( standard::dir::root)),
	userID(new unsigned int(0))
{

}

data::Local_DataManager::
~Local_DataManager()
{
	delete tempFileDirName;
	delete friendsProfileDirName;
}

QString data::Local_DataManager::
helper_combineFileName(unsigned int id, QString* dir)const
{
	QString* idstr = new QString(QString::number(id));
	QString res;

	res.append(*dir);
	res.push_back('/');
	res.append(*idstr);

	delete idstr;
	return res;
}

void data::Local_DataManager::
setupLocalDataInfo(unsigned int id)
{
	QString* sub0_id = new QString(QString::number(id));
	QDir* dir_op = new QDir;

	*this->userID = id;

	tempFileDirName->push_back('/');
	tempFileDirName->append(*sub0_id + '/');
	tempFileDirName->append(standard::dir::sub1_temp);

	friendsProfileDirName->push_back('/');
	friendsProfileDirName->append(*sub0_id + '/');
	friendsProfileDirName->append(QString(standard::dir::sub1_friends)+'/');
	friendsProfileDirName->append(standard::dir::sub2_friends_profile);

	if (!dir_op->exists(*tempFileDirName) )
		dir_op->mkpath(*tempFileDirName);

	if (!dir_op->exists(*friendsProfileDirName) )
		dir_op->mkpath(*friendsProfileDirName);


	delete dir_op;
	delete sub0_id;
}

QString data::Local_DataManager::
getTempFileDirName()const
{
	return *tempFileDirName;
}

QString data::Local_DataManager::
getFriendsProfileDirName()const
{
	return *friendsProfileDirName;
}

void data::Local_DataManager::
updateFriendProfile(unsigned int id,std::shared_ptr<net::NetFileNode> fileNode)
{
	QString filename = helper_combineFileName(id, friendsProfileDirName);

	QFile* file = new QFile(filename);
	file->open(QIODeviceBase::WriteOnly | QIODeviceBase::Unbuffered);
	file->write(fileNode->data.get(),fileNode->bytes);
	file->close();
	delete file;
}

QPixmap data::Local_DataManager::
getFriendProfile(unsigned int id)const
{
	QString filename = helper_combineFileName(id, friendsProfileDirName);
	return QPixmap(filename);
}

unsigned int data::Local_DataManager::
getUserID()const
{
	return *userID;
}
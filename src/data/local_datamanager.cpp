#include"local_datamanager.hpp"
#include"standard.hpp"

#include"qdir.h"

#include<qjsondocument.h>
#include<qjsonobject.h>
#include<qjsonarray.h>
#include<qpair.h>

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


data::Local_DataManager::Local_DataManager() :
	tempFileDirName(new QString),
	friendsProfileDirName(new QString),
	userID(new unsigned int(0)),
	privateChatData(new QHash<QString, QVarLengthArray<QPair<QString, QString>>>),
	privateChat_dataDirName(new QString),
	selfProfile_filename(new QString)
{
}

data::Local_DataManager::~Local_DataManager()
{
	this->savePrivateChatData();
	delete tempFileDirName;
	delete friendsProfileDirName;
}

QString data::Local_DataManager::helper_combineFileName(unsigned int id, QString* dir)const
{
	QString* idstr = new QString(QString::number(id));
	QString res;

	res.append(*dir);
	res.push_back('/');
	res.append(*idstr);

	delete idstr;
	return res;
}

void data::Local_DataManager::setupLocalDataInfo(unsigned int id)
{
	using namespace standard::dir;
	QString* sub0_id = new QString(QString::number(id));
	QDir* dir_op = new QDir;

	*this->userID = id;

	*tempFileDirName = QString("%1/%2/%3").
		arg(root).arg(*sub0_id).arg(sub1_temp);

	*friendsProfileDirName = QString("%1/%2/%3/%4").
		arg(root).arg(*sub0_id).arg(sub1_friends).arg(sub2_friends_profile);

	*privateChat_dataDirName = QString("%1/%2/%3").
		arg(root).arg(this->getUserID()).arg(sub1_privateChat);

	*selfProfile_filename = QString("%1/%2/selfprofile").
		arg(standard::dir::root).arg(QString::number(id));

	if (!dir_op->exists(*tempFileDirName) )
		dir_op->mkpath(*tempFileDirName);

	if (!dir_op->exists(*friendsProfileDirName) )
		dir_op->mkpath(*friendsProfileDirName);

	if (!dir_op->exists(*privateChat_dataDirName))
		dir_op->mkpath(*privateChat_dataDirName);
	
	delete dir_op;
	delete sub0_id;
}

QString data::Local_DataManager::getSelfProfile_filename()const
{
	return *this->selfProfile_filename;
}

QString data::Local_DataManager::getTempFileDirName()const
{
	return *tempFileDirName;
}

QString data::Local_DataManager::getFriendsProfileDirName()const
{
	return *friendsProfileDirName;
}

void data::Local_DataManager::updateFriendProfile(unsigned int id,std::shared_ptr<net::NetFileNode> fileNode)
{
	QString filename = helper_combineFileName(id, friendsProfileDirName);

	QFile* file = new QFile(filename);
	file->open(QIODeviceBase::WriteOnly | QIODeviceBase::Unbuffered);
	file->write(fileNode->data.get(),fileNode->bytes);
	file->close();
	delete file;
}

QPixmap data::Local_DataManager::getFriendProfile(unsigned int id)const
{
	QString filename = helper_combineFileName(id, friendsProfileDirName);
	return QPixmap(filename);
}

unsigned int data::Local_DataManager::getUserID()const
{
	return *userID;
}

void  data::Local_DataManager::loadPrivateChatData()
{
	/*
	* Filename:  userdata/userid/privatechat/otherid.json
		Each object Format:

		otherID_QStr:
			[0] senderID_QStr , content.
			[1] senderID_QStr , content.

	* return: the chatList with every friends.

	*/
	using namespace standard::dir;

	QString& dirname = *this->privateChat_dataDirName;

	QDir dir(dirname);
	auto entries_pre = dir.entryInfoList();
	QFileInfoList entries(entries_pre.begin() + 2, entries_pre.end());
	
	auto& target = this->privateChatData;
	for (auto& e : entries)
	{
		auto filename = QString("%1/%2").arg(dirname).arg(e.fileName());
		QFile file(filename);
		file.open(QIODeviceBase::ReadOnly);
		auto data = file.readAll();

		QJsonDocument jd(QJsonDocument::fromJson(data));

		QJsonArray ja(jd.array());
		
		QVarLengthArray<QPair<QString, QString>> itemVal;
		
		for (auto item : ja)
		{
			auto sender = item.toObject()["sender"].toString();
			auto content = item.toObject()["content"].toString();
			itemVal.push_back({ sender,content });
		}

		(*target)[e.baseName()] = itemVal;
	}
}

void data::Local_DataManager::savePrivateChatData()
{
	//Input to file and then delet
	using namespace standard::dir;

	QString& dirname = *this->privateChat_dataDirName;
	for (auto& otherID : privateChatData->keys())
	{
		auto entries = privateChatData->value(otherID);

		QString filename = QString("%1/%2.json").arg(dirname).arg(otherID);
		QFile out(filename);
		out.open(QIODeviceBase::WriteOnly);

		QJsonArray* ja = new QJsonArray;
		for (auto& entry : entries)
		{
			QJsonObject jo;
			jo["sender"] = entry.first;
			jo["content"] = entry.second;
			ja->push_back(jo);
		}

		QJsonDocument* jd = new QJsonDocument;
		jd->setArray(*ja);

		out.write(jd->toJson());
		delete ja;
	}
	delete this->privateChatData;
}

QHash<QString, QVarLengthArray<QPair<QString, QString>>> data::Local_DataManager::
getPrivateChatData()const
{
	return *privateChatData;
}

void data::Local_DataManager::appendPrivateChatData(QString otherID, QString senderID, QString msg)
{
	(*this->privateChatData)[otherID].push_back({ senderID, msg });
}


void data::Local_DataManager::deletePrivateChatDataItem(QString otherID)
{
	this->privateChatData->remove(otherID);

	QString filename = QString("%1/%2.json").arg(*this->privateChat_dataDirName).arg(otherID);
	QFile file(filename);

	file.remove();
}
/*
	Json format:
		[
			{
				"sender": (QString),
				"content": (QString),
			},

			{
				"sender": (QString),
				"content": (QString),
			}

		]


*/
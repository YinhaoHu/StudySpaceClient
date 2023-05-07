#pragma once

#include"runtime_datamanager.hpp"
#include"net/net.hpp"

#include<qobject.h>
#include<qstring.h>

namespace data {
	class Local_DataManager;
};

class data::Local_DataManager :public QObject
{
	Q_OBJECT
private:
	unsigned int* userID;
	QString* tempFileDirName;

	QString* friendsProfileDirName;
	QString* privateChat_dataDirName;
	QString* selfProfile_filename;

	QHash<QString, QVarLengthArray<QPair<QString, QString>>>* privateChatData;

	QString helper_combineFileName(unsigned int id, QString* dir)const;

	void savePrivateChatData();//Used only in this destructor

public:
	Local_DataManager();
	~Local_DataManager();

public:
	void setupLocalDataInfo(unsigned int id);

	QString getTempFileDirName()const;
	QString getFriendsProfileDirName()const;
	QString getSelfProfile_filename()const;

	void updateFriendProfile(unsigned int id,std::shared_ptr<net::NetFileNode> fileNode);
	QPixmap getFriendProfile(unsigned int id)const;

	void loadPrivateChatData();
	QHash<QString, QVarLengthArray<QPair<QString, QString>>>  getPrivateChatData()const;
	void appendPrivateChatData(QString otherID, QString senderID, QString msg);
	void deletePrivateChatDataItem(QString otherID);

	unsigned int getUserID() const;
};
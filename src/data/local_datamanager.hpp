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

	QString helper_combineFileName(unsigned int id, QString* dir)const;

public:
	Local_DataManager();
	~Local_DataManager();

public:
	void setupLocalDataInfo(unsigned int id);

	QString getTempFileDirName()const;
	QString getFriendsProfileDirName()const;

	void updateFriendProfile(unsigned int id,std::shared_ptr<net::NetFileNode> fileNode);
	QPixmap getFriendProfile(unsigned int id)const;

	unsigned int getUserID() const;
};
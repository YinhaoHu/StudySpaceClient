#ifndef _NETCONTROLLER_HPP_
#define _NETCONTROLLER_HPP_

#include<qobject.h>
#include<qpixmap.h>
#include<qstring.h>
#include<qvarlengtharray.h>

namespace net {
	class NetController;
	void netControllerEntry(NetController* controller);
}

class net::NetController:public QObject {
	Q_OBJECT

private:
	void initComChatRecv_data();

public:
	struct {
		QPixmap senderProfile;
		QString sendername;
		QString msg;
	}comChatRecv_data;

	struct {
		QString* oldPassword;
	}userInfo_change_data;

	struct {
		bool inited = false;
		QVarLengthArray<QString>* id;
		QVarLengthArray<QString>* onlineStatus;
		QVarLengthArray<QString>* intro;
		QVarLengthArray<QString>* name;
	}getFriendList_data;

	NetController() 
	{
		initComChatRecv_data();
	}

public:
	void getFriendList_initData();
	void getFriendList_deleteData();

signals:
	void comChatRecv_update();

	void password_update_signal();
	void changeInfo_update_signal();
	void getFriendList_update_signal();

	void addFriend_Check_signal(QString message);
	void addFriend_Notice_signal(QString name, QString id);
	void addFriend_makeListItem_signal(uint id);

	void addFriend_accepted_signal(QString id);
	void addFriend_rejected_signal(QString id);

	void pureNotice_signal(QString msg);

	void removeFriend_signal(QString ID_toDelete);
};


#endif
#ifndef _NETCONTROLLER_HPP_
#define _NETCONTROLLER_HPP_

#include<qobject.h>
#include<qpixmap.h>
#include<qstring.h>

namespace net {
	class NetController;
	void netControllerEntry(NetController* controller);
}

class net::NetController:public QObject {
	Q_OBJECT

private:
	void initComChatRecv_data()
	{
		comChatRecv_data.senderProfile = QPixmap();
		comChatRecv_data.sendername = QString();
		comChatRecv_data.msg = QString();
	}

public:
	struct {
		QPixmap senderProfile;
		QString sendername;
		QString msg;
	}comChatRecv_data;

	NetController() 
	{
		initComChatRecv_data();
	}
	
signals:
	void comChatRecv_update();
};


#endif
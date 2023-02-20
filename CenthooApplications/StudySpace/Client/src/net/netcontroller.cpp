#include"netcontroller.hpp"

#include"net.hpp"
#include"../standard.hpp"

#include<algorithm>
#include<mutex>
#include<string>

#include<cstdio>

#include<QtGui/qpixmap.h>
#include<QtCore/qstring.h>

using namespace std;
using namespace net;

extern net::Client* clientNet;
extern std::mutex netMutexLock;

std::mutex NetControllerMutexLock;

static inline void comChatRecv_handler();

//Any communication with server should be registered here.
static struct {
	u32string comChatRecv =U"COMCHATRECV";
}cmdList;

static NetController* netController;

void net::netControllerEntry(NetController* controller)
{
	char32_t* eventType;

	netController = controller;
	eventType = new char32_t[net::sockMsgLen];//No need to delete.
	memset(eventType, 0, net::sockMsgBytes);

	while (clientNet->recvMsg(eventType) > 0)
	{
		u32string eventTypeStr = eventType;

		if (equal(eventTypeStr.begin(),eventTypeStr.end(),
			cmdList.comChatRecv.begin(),cmdList.comChatRecv.end()))
		{
			comChatRecv_handler();
		}
	}
}

static inline void comChatRecv_handler()
{
	//Socket Message Format:
	//<USERNMAE>
	//<MSG>
	//<SIZE>
	//<PROFILE SIZE>
	//<PROFILE>
	const int sizeBufBytes = 16, idStrBytes = 16;
	int profile_size;
	char32_t* username_buf, *msg_buf;
	char* profile_buf, profile_sizeStr[sizeBufBytes],id_str[idStrBytes], * end;
	QString usernmae_str, msg_str;
	QPixmap profile_pixmap;

	username_buf = new char32_t[net::sockMsgLen];
	msg_buf = new char32_t[net::sockMsgLen];
	
	memset(username_buf, 0, net::sockMsgBytes);
	memset(msg_buf, 0, net::sockMsgBytes);
	memset(id_str, 0, idStrBytes);

	netMutexLock.lock();

	clientNet->recvMsg(username_buf);
	clientNet->recvMsg(msg_buf);
	clientNet->recvFile(profile_sizeStr, sizeBufBytes);

	profile_size = strtol(profile_sizeStr,&end,10);
	profile_buf = new char[profile_size];
	
	clientNet->recvFile(id_str, idStrBytes);
	clientNet->recvFile(profile_buf, profile_size);

	netMutexLock.unlock();

	char tempFilename[standard::size::fieldBytes];
	memset(tempFilename, 0, standard::size::fieldBytes);
	strcpy(tempFilename, standard::file::tempFileDir);
	strcat(tempFilename, "profile");
	strcat(tempFilename, id_str);
	strcat(tempFilename, ".jpg");
	
	FILE* tempFile = fopen(tempFilename, "wb");
	fwrite(profile_buf, sizeof(char), profile_size, tempFile);
	fclose(tempFile);

	profile_pixmap.load(tempFilename);
	usernmae_str = QString::fromStdU32String(username_buf);
	msg_str = QString::fromStdU32String(msg_buf);


	NetControllerMutexLock.lock();
	netController->comChatRecv_data.msg = msg_str;
	netController->comChatRecv_data.sendername = usernmae_str;
	netController->comChatRecv_data.senderProfile = profile_pixmap;
	NetControllerMutexLock.unlock();

	emit netController->comChatRecv_update();
}
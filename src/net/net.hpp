#ifndef _NET_HPP
#define _NET_HPP

#pragma comment(lib,"Ws2_32.lib")

#include<WinSock2.h>
#include<ws2tcpip.h>

#include<qstring.h>
#include<qsharedpointer.h>
#include<memory>

namespace net 
{
	const size_t maxFieldSize = 64;//Limites bytes for sock field.
	const size_t sockMsgBytes = 4096;//Limit bytesof recv() and send()
	const size_t sizeInfoBytes = 16;
	const size_t sockMsgLen = 1024;

	struct serverInfo;
	struct NetFileNode;
	class Client;

	extern inline void getConfig(net::serverInfo* result);
	extern inline int setUp();
}

//Declarations.
struct net::serverInfo {
char host[net::maxFieldSize];
char port[net::maxFieldSize];
};


struct net::NetFileNode {
	size_t bytes;
	std::shared_ptr<char> data;

	NetFileNode(size_t _bytes = 0UL, char* _data = nullptr)
		:bytes(_bytes), data(std::shared_ptr<char>(_data))
	{}
	~NetFileNode(){}
};

class net::Client {
public:
	Client(const serverInfo* info);
	Client(const char* serverhost, const char* serverport);
	~Client();

	void connectToServer();
	void sendMsg(const char32_t* msg);
	int recvMsg(char32_t* result);
	int recvFile(char*fileBuffer,int bytes);
	void sendFile(char* fileBuffer, int bytes);

	void easySend_Msg(QString&& msg);

	void easySend_Request(QString&& request, uint senderID);
	void easySend_Request(QString&& request, QString&& senderID);
	void easySend_U32String(QString&& qstring);
	void easySend_U32String(std::u32string&& u32string);
	void easySend_File(QString&& filename);

	QSharedPointer<QString> easyRecv_QString_U32();
	std::shared_ptr<net::NetFileNode> easyRecv_File();

	SOCKET getSocket()const;
	int getErrNum() const;
	bool fail() const;

private:
	SOCKET clientSocket;
	char host[net::maxFieldSize];
	char port[net::maxFieldSize];
	int errorNum;
};



#endif
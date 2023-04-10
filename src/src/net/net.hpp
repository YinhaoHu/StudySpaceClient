#ifndef _NET_HPP
#define _NET_HPP

#pragma comment(lib,"Ws2_32.lib")

#include<WinSock2.h>
#include<ws2tcpip.h>


namespace net 
{
	const int maxFieldSize = 64;//Limites bytes for sock field.
	const int sockMsgBytes = 4096;//Limit bytesof recv() and send()
	const int sockMsgLen = 1024;
	struct serverInfo;
	class Client;

	extern inline void getConfig(net::serverInfo* result);
	extern inline int setUp();
}

//Declarations.
struct net::serverInfo {
char host[net::maxFieldSize];
char port[net::maxFieldSize];
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
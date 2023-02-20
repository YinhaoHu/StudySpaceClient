//net.cpp -- Support for the network communication between server and client.
#include"net.hpp"
#include"../standard.hpp"
#include"../../lib/CenthooLib/HData/HData.hpp"

#include<exception>

#include<cstring>

using namespace ceh::Data;
using namespace net;

//Common functions in the net of this project
inline void net::getConfig(serverInfo* result)
{
	HData hfile(standard::file::netConfigFile);

	hfile.load();
	//Exception should be considered.
	if (hfile.size() < 2)
	{
		throw std::exception("Error in config");
	}
	else
	{
		strcpy(result->host, hfile[0].values[0].c_str());
		strcpy(result->port, hfile[1].values[0].c_str());
	}
}
inline int net::setUp() {
	WSADATA wsadat;
	int errorNum;

	errorNum = WSAStartup(MAKEWORD(2, 2), &wsadat);

	return errorNum;
}

//Implementation of Class Client
Client::Client(const serverInfo* info)
{
	clientSocket = 0;
	errorNum = 0;
	strcpy(host, info->host);
	strcpy(port, info->port);
}

Client::Client(const char* serverhost, const char* serverport)
{	
	clientSocket = 0;
	errorNum = 0;
	strcpy(host,serverhost);
	strcpy(port, serverport);
}

Client::~Client()
{
	closesocket(clientSocket);
}

void Client::sendMsg(const char32_t* msg)
{
	send(clientSocket, reinterpret_cast<const char*>(msg), net::sockMsgBytes, 0);
}

int Client::recvMsg(char32_t* result) {
	int size;
	size = recv(clientSocket, reinterpret_cast<char*>(result), net::sockMsgBytes, MSG_WAITALL);
	return size;
}

int Client::recvFile(char* fileBuffer,int bytes)
{
	int size;
	size = recv(clientSocket, fileBuffer, bytes, MSG_WAITALL);
	return size;
}
void Client::sendFile(char* fileBuffer, int bytes)
{
	send(clientSocket, fileBuffer, bytes, 0);
}

int Client::getErrNum()
{
	return errorNum;
}

bool Client::fail()
{
	return errorNum;
}

SOCKET Client::getSocket()
{
	return clientSocket;
}

void Client::connectToServer()
{
	SOCKET clientfd;
	addrinfo hints, * p, * listp;

	memset(&hints, 0, sizeof(addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICSERV | AI_ADDRCONFIG;
	getaddrinfo(host, port, &hints, &listp);

	for (p = listp; p; p = p->ai_next)
	{
		if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
			continue;

		if (connect(clientfd, p->ai_addr, p->ai_addrlen) == 0)
			break;

		errorNum = 10002;
		return;
	}
	freeaddrinfo(listp);
	if (!p)
	{
		errorNum = 10001;
		return;
	}

	char temp[4];
	//For testing connection
	if (recv(clientfd, temp, 4, MSG_WAITALL) !=4)
	{
		errorNum = 10003;
		return;
	}
	
	clientSocket = clientfd;
}
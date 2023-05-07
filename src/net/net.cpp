//net.cpp -- Support for the network communication between server and client.
/*
		-----------------------------------------------------
			ERROR			LIST	
	
		ERRORNUM			EXPLANATION
		10001				socket() error
		10002				connect() error
		10003				can't communicate with the server
		-----------------------------------------------------
*/
#include"net.hpp"

#include<exception>
#include<cstring>

#include<qfile.h>

using namespace net;

//Common functions in the net of this project

inline int net::setUp() {
	WSADATA wsadat;
	int errorNum;

	errorNum = WSAStartup(MAKEWORD(2, 2), &wsadat);

	return errorNum;
}

//Implementation of Class Client
Client::Client(const serverInfo* info)
	:clientSocket(0),errorNum(0)
{
	strcpy(host, info->host);
	strcpy(port, info->port);
}

Client::Client(QString _ip, QString _port)
	:clientSocket(0), errorNum(0)
{
	strcpy(host, _ip.toStdString().c_str());
	strcpy(port, _port.toStdString().c_str());
}

Client::Client(const char* serverhost, const char* serverport)
	:clientSocket(0), errorNum(0)
{	
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

//Created for compatable send msg.
void Client::easySend_Msg(QString&& _msg)
{
	char32_t* msg = new char32_t[net::sockMsgLen];
	size_t _msgBytes = _msg.length() * sizeof(char32_t);

	memset(msg, 0, net::sockMsgBytes);
	memcpy(msg, _msg.toStdU32String().c_str(), 
		_msgBytes);

	this->sendMsg(msg);
	delete[] msg;
}

void Client::easySend_Request(QString&& request,uint senderID)
{
	easySend_Request(std::move(request), std::move(QString::number(senderID)));
}

void Client::easySend_Request(QString&& request, QString&& senderID)
{
	request.append(" ");
	request.append(senderID);
	easySend_Msg(std::move(request));
}

void Client::
easySend_U32String(QString&& msg)
{
	size_t bytes = msg.length() * sizeof(char32_t);
	char* sendMsg = new char[bytes];
	char* sendSize = new char[sizeInfoBytes];
	QString* sizeString = new QString;

	sizeString->setNum(bytes);
	memset(sendSize, 0, sizeInfoBytes);
	memcpy(sendSize, sizeString->toStdString().c_str(), sizeInfoBytes);

	memset(sendMsg, 0, bytes);
	memcpy(sendMsg, msg.toStdU32String().c_str(), bytes);

	send(clientSocket, sendSize, sizeInfoBytes, 0);
	send(clientSocket, sendMsg, bytes, 0);

	delete[] sendMsg;
	delete[] sendSize;
	delete sizeString;
}

void Client::
easySend_U32String(std::u32string&& msg)
{
	size_t bytes = msg.length() * sizeof(char32_t);
	char* sendMsg = new char[bytes];
	char* sendSize = new char[sizeInfoBytes];
	QString* sizeString = new QString;

	sizeString->setNum(bytes);
	memset(sendSize, 0, sizeInfoBytes);
	memcpy(sendSize, sizeString->toStdString().c_str(), sizeInfoBytes);

	memset(sendMsg, 0, bytes);
	memcpy(sendMsg, msg.c_str(), bytes);

	send(clientSocket, sendSize, sizeInfoBytes, 0);
	send(clientSocket, sendMsg, bytes, 0);

	delete[] sendMsg;
	delete[] sendSize;
	delete sizeString;
}

void Client::
easySend_File(QString&& filename)
{
	char* sendSize;
	char* sendMsg;
	size_t fileSize;
	QString* fileSizeInfo;
	QFile* file;
	QByteArray* fileData;

	file = new QFile(filename);
	fileData = new QByteArray;

	file->open(QIODeviceBase::ReadOnly | QIODeviceBase::Unbuffered);
	*fileData = file->readAll();
	file->close();

	fileSize = fileData->size();
	fileSizeInfo = new QString;
	fileSizeInfo->setNum(fileSize);

	sendSize = new char[sizeInfoBytes];
	sendMsg = new char[fileSize];

	memset(sendSize, 0, sizeInfoBytes);
	memcpy(sendSize, fileSizeInfo->toStdString().c_str(), sizeInfoBytes);

	memcpy(sendMsg, fileData->constData(), fileSize);

	send(clientSocket, sendSize, sizeInfoBytes, 0);
	send(clientSocket, sendMsg, fileSize, 0);

	delete[] sendSize;
	delete[] sendMsg;
	delete file;
	delete fileSizeInfo;
	delete fileData;
}

QSharedPointer<QString>  Client::
easyRecv_QString_U32()
{
	char* sizeStr = new char[sizeInfoBytes];
	char32_t* u32str;
	size_t bytes;

	memset(sizeStr, 0, sizeInfoBytes);
	recv(clientSocket, sizeStr, sizeInfoBytes, MSG_WAITALL);
	bytes = atol(sizeStr);


	u32str = new char32_t[bytes / sizeof(char32_t)];
	memset(u32str, 0, bytes);
	recv(clientSocket, reinterpret_cast<char*>(u32str), bytes, MSG_WAITALL);

	auto res = QSharedPointer<QString>
		(new QString(QString::fromStdU32String(u32str)));
	res->resize(bytes / sizeof(char32_t));
	
	delete[] sizeStr;
	delete[] u32str;

	return res;
}

std::shared_ptr<net::NetFileNode> Client::
easyRecv_File()
{
	size_t filesize;
	char* filedata;
	char* filesizeStr;

	filesizeStr = new char[sizeInfoBytes];
	memset(filesizeStr, 0, sizeInfoBytes);

	recv(clientSocket, filesizeStr, sizeInfoBytes, MSG_WAITALL);
	filesize = atol(filesizeStr);

	filedata = new char[filesize];
	memset(filedata, 0, filesize);
	recv(clientSocket, filedata, filesize, MSG_WAITALL);

	delete[] filesizeStr;
	auto res = std::make_shared<net::NetFileNode>(filesize, filedata);
	return res;
}

int Client::getErrNum()const
{
	return errorNum;
}

bool Client::fail()const
{
	return errorNum != 0;
}

SOCKET Client::getSocket()const
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
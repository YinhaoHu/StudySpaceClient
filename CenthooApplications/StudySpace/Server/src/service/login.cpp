#include"login.hpp"
#include"../../lib/HData/HData.hpp"
#include"../server/net.hpp"
#include"../server/standard.hpp"
#include"../../lib/HString/HString.hpp"

#include<fcntl.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<unistd.h>

#include<fstream>
#include<unordered_map>
#include<mutex>

#include<cstdio>
#include<cstring>
#include<cwchar>

using namespace std;
using namespace ceh::Data;
using namespace ceh::String;

const char* usersFile = "data/users.hdat";

extern unordered_map<userID_t, userFD_t> onlineUsers;
extern mutex onlineUsersMutexLock;

static inline int checkInfo(wchar_t* id_str, userID_t id,wchar_t* password, HWData* data);
static inline void sendUserInit(userID_t id, HWData* usersData,int sock);


void doLogin(serviceInfo* info)
{
    wchar_t password[maxFieldSize], id[maxFieldSize], sendBUf[maxSockBufferSize];
    char sendMsg[maxSockBufferBytes];
    HWData userdata(usersFile);
    int statusCode;

    userdata.load();
    uintToWStr(info->userid, id);
    wcscpy(password, info->args);
    statusCode = checkInfo(id, info->userid,password, &userdata);
    switch (statusCode)
    {
        case 1: 
            wcscpy(sendBUf, L"OK");
            onlineUsersMutexLock.lock();
            onlineUsers[info->userid] = info->userfd;
            onlineUsersMutexLock.unlock();
            break;
        case 2: wcscpy(sendBUf, L"WRONG");break;
        case 3: wcscpy(sendBUf,L"NOTEXIST");break;
        case 4: wcscpy(sendBUf, L"LOGINED");break;
        default: wcscpy(sendBUf, L"UNKNOWN");
    }
    memcpy(sendMsg, sendBUf,maxSockBufferBytes);
    send(info->userfd, sendMsg, maxSockBufferBytes, 0);
    showMinior(L"SEND",sendBUf);

    if(statusCode == 1)
    sendUserInit(info->userid,&userdata, info->userfd);

    userdata.save();
}

static inline int checkInfo(wchar_t* id_str, userID_t id,wchar_t* password, HWData* data)
{
    int statusCode;
    wchar_t* end;
  
    statusCode = 1;
    if(-1 == data->findKey(id_str))
        statusCode = 3;
    else if(wcscmp(data->access(id-standard::userid_begin).values[standard::userDataField::password].c_str(), password))
        statusCode = 2;
    else if(onlineUsers.find(id) != onlineUsers.end())
        statusCode = 4;
    return statusCode;
}

static inline void sendUserInit(userID_t id, HWData* usersData,int sockfd){
    HWDataItem_value username;
    wchar_t* usernameBuffer;
    char* userProfileBuffer,  userProfileFile[64], idStr[15], fileSizeStr[maxFieldSize];
    int fileSize, openfd;
    struct stat profileFileStatBuffer;
    FILE* file;

    usernameBuffer = new wchar_t[maxSockBufferSize];
    username = usersData->access(id-standard::userid_begin).values[standard::userDataField::username];
    wcscpy(usernameBuffer, username.c_str());

    
    uintToStr(id,idStr);
    strcpy(userProfileFile, standard::userProfileDir);
    strcat(userProfileFile,idStr);
    stat(userProfileFile,&profileFileStatBuffer);
    fileSize = profileFileStatBuffer.st_size;
    uintToStr(fileSize, fileSizeStr);
    userProfileBuffer = new char[fileSize];
    memset(userProfileBuffer,0 ,fileSize);

    file = fopen(userProfileFile, "rb");
    fread(userProfileBuffer, sizeof(char), fileSize, file);

    send(sockfd,usernameBuffer,maxSockBufferBytes, 0);
    showMinior(L"SEND", usernameBuffer);
    send(sockfd,fileSizeStr, maxFieldSize, 0);
    send(sockfd, userProfileBuffer, fileSize,0);
    showMinior(L"SEND PROFILE FILE", username.c_str());

    fclose(file);
    delete[] userProfileBuffer;
    delete[] usernameBuffer;
}
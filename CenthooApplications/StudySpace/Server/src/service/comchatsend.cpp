#include"comchatsend.hpp"

#include"../server/standard.hpp"
#include"../../lib/HData/HData.hpp"
#include"../../lib/HString/HString.hpp"
#include"../server/net.hpp"

#include<sys/socket.h>
#include<sys/stat.h>

#include<mutex>
#include<unordered_map>

#include<cstdio>
#include<cstring>
#include<cwchar>

using namespace std;
using namespace ceh::Data;
using namespace ceh::String;

extern unordered_map<userID_t, userFD_t> onlineUsers;
extern mutex onlineUsersMutexLock;

void doComChatSend(serviceInfo* info)
{
    const int filesize_bufsize = 16, id_bufsize = 16;
    wchar_t *username, *msg,*eventType;
    char profile_filesize[filesize_bufsize], userid[id_bufsize], *profile_file;
    char userprofile_filename[maxFieldSize], *end;
    struct stat profile_sbuf;
    HWData usersDataFile(standard::userDataFile);

    usersDataFile.load();
    username = new wchar_t[maxSockBufferSize];
    msg = new wchar_t[maxSockBufferSize];

    memset(username,0,maxSockBufferBytes);
    memset(msg,0,maxSockBufferBytes);
    memset(profile_filesize, 0, filesize_bufsize);
    memset(userid, 0, id_bufsize);

    uintToStr(info->userid, userid);
    strcpy(userprofile_filename, standard::userProfileDir);
    strcat(userprofile_filename, userid);
    stat(userprofile_filename , &profile_sbuf);

    wcscpy(username, usersDataFile[info->userid - standard::userid_begin].values[0].c_str());
    wcscpy(msg, info->args);
    uintToStr(profile_sbuf.st_size, profile_filesize);

    profile_file = new char[profile_sbuf.st_size];
    memset(profile_file, 0, profile_sbuf.st_size);

    FILE* userProfileFile;
    userProfileFile = fopen(userprofile_filename, "rb");
    fread(profile_file, sizeof(char), profile_sbuf.st_size, userProfileFile);

    eventType = new wchar_t[maxSockBufferSize];
    wcscpy(eventType, L"COMCHATRECV");
    for(auto& user : onlineUsers)
    {
        if(user.first != info->userid)
        {
            send(user.second, eventType, maxSockBufferBytes, 0);
            send(user.second, username, maxSockBufferBytes, 0);
            send(user.second, msg, maxSockBufferBytes, 0);
            send(user.second, profile_filesize, filesize_bufsize, 0);
            send(user.second, userid, id_bufsize, 0);
            send(user.second, profile_file, profile_sbuf.st_size, 0);
        }
    }
    fclose(userProfileFile);
    
    showMinior(L"FINISH", L"COMCHATSEND");

    delete[] eventType;
    delete[] username;
    delete[] msg;
    delete[] profile_file;
    usersDataFile.save();
}
/*
Design
    get the msg and userid.
    get the (pixmap and username ) of the userid.
    send the formatted msg.
*/
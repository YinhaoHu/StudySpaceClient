#include"register.hpp"

#include"../server/net.hpp"
#include"../server/standard.hpp"
#include"../../lib/HString/HString.hpp"
#include"../../lib/HData/HData.hpp"

#include<sys/socket.h>
#include<sys/stat.h>

#include<algorithm>
#include<string>

#include<cwchar>
#include<cstring>

using namespace std;
using namespace ceh::Data;
using namespace ceh::String;

const char* registerFile = "data/users.hdat";
const char* codeFile = "data/code.hdat";

struct RegisterInfo{
    wchar_t username[maxFieldSize];
    wchar_t password[maxFieldSize];
    wchar_t code[maxFieldSize];
    wchar_t email[maxFieldSize];
    wchar_t year[maxFieldSize];
    wchar_t month[maxFieldSize];
    wchar_t day[maxFieldSize];
    wchar_t allocatedId[maxFieldSize];
};

static void parseInfo(serviceInfo* info, RegisterInfo* result);
static int checkInfo(RegisterInfo* info, HWData* userdata, HWData* codedata);
static inline void generateUserData(int id);

void doRegister(serviceInfo* info)
{
    wchar_t sendBuf[maxSockBufferSize];
    char sendMsg[maxSockBufferBytes];
    int status;
    HWData userinfoData(registerFile), codeData(codeFile);
    RegisterInfo registerinfo;

    userinfoData.load();
    codeData.load();

    parseInfo(info, &registerinfo);
    status = checkInfo(&registerinfo, &userinfoData, &codeData);
    switch(status)
    {    
        case 0: 
            wcscpy(sendBuf, L"OK ");
            wcscat(sendBuf,registerinfo.allocatedId);
            break;
        case 1: wcpcpy(sendBuf, L"EMAIL");break;
        case 2: wcpcpy(sendBuf, L"NAME");break;
        case 3: wcpcpy(sendBuf, L"CODE");break;
        default: wcpcpy(sendBuf,L"UNKNOWN");
    }
    memcpy(sendMsg, sendBuf,maxSockBufferBytes);
    send(info->userfd, sendMsg, maxSockBufferBytes, 0);
    showMinior(L"SEND",sendBuf);
    wchar_t* end;
    generateUserData(wcstol(registerinfo.allocatedId, &end, 10));
    userinfoData.save();
    codeData.save();
}

static void parseInfo(serviceInfo* info, RegisterInfo* result)
{
    wchar_t delimeter,*first, *second;
    wchar_t* third, *fourth, *fifth, *sixth;

    delimeter = L' ';
    first = findwchr(info->args, delimeter);
    second = findwchr(first+1, delimeter);
    third = findwchr(second+1, delimeter);
    fourth = findwchr(third+1, delimeter);
    fifth = findwchr(fourth+1, delimeter);
    sixth = findwchr(fifth+1, delimeter);

    *first = L'\0';
    *second = L'\0';
    *third = L'\0';
    *fourth = L'\0';
    *fifth = L'\0';
    *sixth = L'\0';

    wcscpy(result->username, info->args);
    wcscpy(result->password, first+1);
    wcscpy(result->code , second+1);
    wcscpy(result->email , third+1);
    wcscpy(result->year , fourth+1);
    wcscpy(result->month , fifth+1);
    wcscpy(result->day, sixth+1);
}
static int checkInfo(RegisterInfo* info, HWData* userdata, HWData* codedata)
{
    HWDataItem newUser;

    if(-1 != userdata->findValue(info->email, 2))
        return 1;
    else if(-1 != userdata->findValue(info->username,0))
        return 2;
    else if(-1 == codedata->findKey(info->code))
        return 3;
    
    uintToWStr(10001+ userdata->size(), info->allocatedId);
    newUser.key = info->allocatedId;
    newUser.values = {info->username, info->password, info->email, info->year, info->month, info->day};
    userdata->append(newUser);
    return 0;
}

static inline void generateUserData(int id)
{
    char defaultProfile_filename[maxFileSize], userProfile_filename[maxFieldSize];
    char useridstr[16], *profile_buffer;
    FILE* defaultProfile_file, *userProfile_file;
    struct stat profile_sbuf;

    uintToStr(id, useridstr);
    strcpy(defaultProfile_filename, standard::dataFileDir);
    strcat(defaultProfile_filename, "defaultprofile");
    strcpy(userProfile_filename, standard::userProfileDir);
    strcat(userProfile_filename, useridstr);

    defaultProfile_file = fopen(defaultProfile_filename, "rb");
    userProfile_file = fopen(userProfile_filename, "wb");

    stat(defaultProfile_filename, &profile_sbuf);
    profile_buffer = new char[profile_sbuf.st_size];
    fread(profile_buffer, sizeof(char), profile_sbuf.st_size, defaultProfile_file);
    fwrite(profile_buffer, sizeof(char), profile_sbuf.st_size, userProfile_file);

    fclose(userProfile_file);
    fclose(defaultProfile_file);
    delete profile_buffer;
}
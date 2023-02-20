#include"server.hpp"
#include"standard.hpp"
#include"../server/net.hpp"
#include"../service/service.hpp"
#include"../../lib/HString/HString.hpp"
#include<sys/socket.h>
#include<unistd.h>

#include<malloc.h>
#include<wchar.h>
#include<cstdio>
#include<cstring>

using namespace std;
using namespace ceh::String;


void serve(int connfd)
{
    void* buf = malloc(maxSockBufferBytes);
    serviceInfo* info = new serviceInfo;

    info->userfd = connfd;
    while(recv(connfd, buf, maxSockBufferBytes, 0) > 0)
    {
        showMinior(L"RECV",(wchar_t*)buf);
        if(parse(buf, info) < 0)
        {    
            showMinior(L"RUBBISH FILTER", (wchar_t*)buf);
            continue;
        }
        servicePerform(info);
    }
    showMinior(L"END",L"---");
    free(buf);
    delete info;
}

int parse(void* buf, serviceInfo* result)
{
    wchar_t* thebuf = static_cast<wchar_t*>(buf);
    wchar_t* firstSpace, *secondSpace;
    wchar_t* numEnd;

    if(wcslen((wchar_t*)buf) == 0)
        return -1;

    firstSpace = findwchr(thebuf, L' ');
    
    if(nullptr == firstSpace)
        return -1;

    secondSpace = findwchr(firstSpace+1, L' ');
    *firstSpace = L'\0';
    if(secondSpace != nullptr)
        *secondSpace = L'\0';
    
    wcscpy(result->prog,thebuf);
    wcscpy(result->userid_str, firstSpace+1);
    result->userid = wcstoull(firstSpace+1,&numEnd ,10);
    if(secondSpace != nullptr)
        wcscpy(result->args, secondSpace+1);
    else
        result->args[0] = L'\0';

    return 0;
}
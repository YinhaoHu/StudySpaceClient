#include"net.hpp"
#include"guard.hpp"
#include"../../lib/HTime/HTime.hpp"

#include<netdb.h>
#include<sys/socket.h>
#include<unistd.h>

#include<cwchar>
#include<cstring>
#include<cstdio>

const int listenLimit = 8192;

int openListenfd(char* port)
{
    int listenfd, optval = 1;
    addrinfo hints, *result, *p;

    memset((void*)&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_ADDRCONFIG | AI_NUMERICSERV | AI_PASSIVE;
    if(int errNum = getaddrinfo(nullptr, port, &hints, &result))
    {    
        errorExit(L"[Error] openListenfd: getaddrinfo() - ");
    }

    for(p = result; p != nullptr; p= p->ai_next)
    {
        if((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
            continue;
        
         setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,(const void*)&optval, sizeof(int));// ?

         if(bind(listenfd, p->ai_addr, p->ai_addrlen) ==  0)
            break;
        close(listenfd);
    }
    freeaddrinfo(result);

    if(p == nullptr)
        return -1;
    if(listen(listenfd, listenLimit) < 0)
    {    
        close(listenfd);
        return -1;
    }
    return listenfd;
}

void showMinior(const wchar_t* type,const wchar_t* msg)
{
    ceh::Time::HTime htime;

    wprintf(L"\t[TIME %2d:%2d:%2d] %ls\n\t\t\t%ls\n", htime.getHourByInt()+8, htime.getMinByInt(),
                        htime.getSecByInt(),type,msg);
}
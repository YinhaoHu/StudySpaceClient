//driver.cpp -- The driver of the server.

#include"../../lib/HData/HData.hpp"

#ifndef HDATA_FOR_SERVER_LOCAL_en_USUTF8
#error "[lib]Make sure the ustf8 local set in HData & HWData construtor is en_utf8."
#endif

#include"server.hpp"
#include"guard.hpp"
#include"net.hpp"
#include"standard.hpp"

#include<mutex>
#include<string>

#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<pthread.h>

#include<cwchar>
#include<cstdlib>
#include<cstring>

using namespace std;

unsigned long long eventCount = 1;
void* serviceThread(void* argv);

int main(int argc, char* argv[])
{
    int listenfd, connfd;
    char clienthost[maxFieldSize], clientport[maxFieldSize];
    const char* vertifacation = "LIK";
    sockaddr_storage clientaddr;
    socklen_t clientaddrlen;
    pthread_t tid;

    if(argc != 2)
    {
        fwprintf(stderr, L"Usage: %s <port>", argv[0]);
        exit(0);
    }

    if((listenfd = openListenfd(argv[1]) )< 0)
        errorExit(L"[Error] main(): openListenfd");

    while(1)
    {
        clientaddrlen = sizeof(sockaddr_storage);
        connfd = accept(listenfd, (sockaddr*)& clientaddr, &clientaddrlen);
        getnameinfo((sockaddr*)&clientaddr, clientaddrlen, clienthost, maxFieldSize, 
                                clientport, maxFieldSize, 0);
        wprintf(L"[Connection: %lld] Connected to (%s : %s)\n", 
            eventCount,clienthost, clientport);
        send(connfd, vertifacation,4,0);
        ++eventCount;

        int* workfd = new int(connfd);
        pthread_create(&tid, NULL, serviceThread, static_cast<void*>(workfd));
    }    
    return 0;
}
void* serviceThread(void* argv)
{
    int connfd = *static_cast<int*>(argv);

    delete static_cast<int*>(argv);
    pthread_detach(pthread_self());
    serve(connfd);
    close(connfd);
    return NULL;
}
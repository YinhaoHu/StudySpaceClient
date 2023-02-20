#include"service.hpp"
#include"register.hpp"
#include"login.hpp"
#include"comchatsend.hpp"

#include<unordered_map>
#include<mutex>

#include<cstring>
using namespace std;

unordered_map<userID_t, userFD_t> onlineUsers;
mutex onlineUsersMutexLock;

void servicePerform(serviceInfo* info)
{
    if(wcscmp(L"REGISTER", info->prog) == 0)
    {
        doRegister(info);
    }
    else if(wcscmp(L"LOGIN", info->prog) == 0)
    {
        doLogin(info);
    }
    else if(wcscmp(L"COMCHATSEND", info->prog) == 0)
    {
        doComChatSend(info);
    }
    else
        wprintf(L"UNKNOW PROG\n");
}
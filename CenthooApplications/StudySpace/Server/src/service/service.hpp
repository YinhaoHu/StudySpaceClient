#ifndef _SERVICE_HPP_
#define _SERVICE_HPP_

#include"../server/standard.hpp"

using userID_t = unsigned long long;
using userFD_t = int;

struct serviceInfo{
    wchar_t prog[maxFieldSize];
    userID_t userid;
    userFD_t userfd;
    wchar_t args[maxArgsSize];
    wchar_t userid_str[maxFieldSize];
};

void servicePerform(serviceInfo* info);



#endif
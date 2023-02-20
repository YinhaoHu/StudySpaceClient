#include"guard.hpp"

#include<cstdio>
#include<cstdlib>
#include<cwchar>

void errorMsg(const wchar_t* msg)
{
    fwprintf(stderr, msg);
}
void errorExit(const wchar_t* msg)
{
    fwprintf(stderr, msg);
    exit(0);
}
#ifndef _SERVER_HPP
#define _SERVER_HPP
#include"../service/service.hpp"
 
void serve(int connfd);
int parse(void* buf, serviceInfo*result);


#endif
#include"net/net.hpp"
#include"net/netcontroller.hpp"

#include<mutex>


#ifndef _MAINWINDOW_
extern 
#endif 
net::NetController* netController;


#ifndef _MAINWINDOW_
extern
#endif  

std::mutex NetControllerMutexLock;


#ifndef _CLIENT_DRIVER_
extern 
#endif
net::Client* clientNet;

#ifndef _CLIENT_DRIVER_
extern 
#endif 
std::mutex netMutexLock;

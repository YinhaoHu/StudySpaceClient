#include"net/net.hpp"
#include"net/netcontroller.hpp"
#include<mutex>

extern net::NetController* netController;
extern std::mutex NetControllerMutexLock;
extern net::Client* clientNet;
extern std::mutex netMutexLock;

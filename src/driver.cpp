//driver.cpp: the entry program.
#define _CLIENT_DRIVER_

#include"net/net.hpp"
#include"net/netcontroller.hpp"
#include"model/main/mainwindow.hpp"
#include"model/login/loginwindow.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"inc_data/extern_data.hpp"
#include"inc_net/extern_net.hpp"
#include"inc_data/extern_config.hpp"

#include<qapplication.h>

static inline void checkLocalConfig();
static inline int setupNet();
static inline void startProgram();
static inline void quitApplication();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    startProgram();

    auto code = a.exec();

    quitApplication();

    return code;
}

static inline void checkLocalConfig()
{
    //Left for check Local config.
    //Like config folder, userdata folder.
    ::config_manager = new ConfigManager;
}

static inline int setupNet()
{
    int netSetUpErrNum;

    netSetUpErrNum = net::setUp();

    if (netSetUpErrNum != 0)
    {
        //Remains for exception handler.
        
    }

    auto ip = config_manager->get_netConfigIP();
    auto port = config_manager->get_netConfigPort();

    clientNet = new net::Client(ip, port);
    clientNet->connectToServer();
    if (clientNet->fail())
    {
        tipWindow->inform(QString("连接服务器失败,请检查网络配置文件 或者 查看服务器是否开启.错误码是:%1 %2").
            arg(clientNet->getErrNum()).arg(netSetUpErrNum));
        return -1;
    }
    return 0;
}

static inline void startProgram()
{
    LoginWindow* loginWindow = new LoginWindow;
    MainWindow* mainWindow = new MainWindow;
    tipWindow = new TipWindow;

    tipWindow->inform("正在启动程序...");
    checkLocalConfig();
    if (0 == setupNet())
    {
        QObject::connect(loginWindow, SIGNAL(properLogin()), mainWindow, SLOT(init()));
        QObject::connect(loginWindow, SIGNAL(properLogin()), loginWindow, SLOT(close()));

        loginWindow->launch();
    }
}

static inline void quitApplication()
{
    QString cmdString(QString::fromStdU32String(U"USERQUIT ").
        append(QString::number(local_dataManager->getUserID())));
    clientNet->easySend_Msg(std::move(cmdString));

    delete config_manager;
}
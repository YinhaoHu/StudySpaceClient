# Centhoo Application: StudySpace 设计文档

---

## 一、架构模型<img title="" src="file:///D:/PersonalFilesBase/[Programming]CPlusPlus/Projects/Centhoo/CenthooApplications/StudySpaceClient/docs/Structure.png" alt="" width="661">

### 1.客户端

*约定：Diagram1中的上方End Contorller为Sender Controller(传送控制器)，下方End Controller为Receiver Controller(接收控制器)。*

*指导：View用Qt实现，如果需要的Model是基于STL或者其他库实现且涉及不同类型数据，Controller实现从Qt数据类型到目标数据类型的转换。*

- View：用户界面实现。
  
- Model：数据存储和处理。
  
- Controller：使得Model和View能够通信。如果有必要的话，实现数据类型转换。
  
- Sender Controller：接受Model的数据，封装并转发。如果有必要的话，实现数据类型转换，转换后发送给服务端。
  
- Receiver Controller：接受Server的数据，解析并转发。如果有必要的话，实现数据类型转换，转换后发送给Model。
  

### 2.服务端

- 服务端应当解析来自客户端的请求后响应。

### 3.通信

- 客户端实现平台：Windows
  
- 服务端实现平台：Linux
  
- 传输数据类型：char *
  
- 客户端请求格式：
  
  `Prog UserID Agrs`
  
- 服务端相应格式：
  
  `Ret`
  
- 通信数据规范
  
  - 用于send() 和 recv() 的数据类型为：char32_t(on Windows), wchar(on Linux),大小为4096字节。

---

## 二、客户端实现

### 1. LoginWindow

*——考虑实现之前，务必思考需要Qt支持什么，然后寻找QtAPI、QtTutorial的案例进行学习*

*——参考C++文档以及时巩固语法知识。参考EffectiveC++以便提高代码效果*

- 异常处理
  
  - 无法连接到服务器
- 其他
  
  - <u>LoginWindow可以从HLearnWord的登录界面修改而来</u>。

### 2. MainWindow

*——考虑实现之前，务必思考需要Qt支持什么，然后寻找QtAPI、QtTutorial的案例进行学习*

*——参考C++文档以及时巩固语法知识。参考EffectiveC++以便提高代码效果*

### 3. Files

- config.hdat: 客户端配置文件，其字段含义如下。
  
  `ServerInfo ServerHost ServerPort`
  
  `LoginFreeEnd YEAR MONTH DAY`
  

---

## 三、服务端实现

### 1. 服务器选型

*——参考C++文档以及时巩固语法知识。参考EffectiveC++以便提高代码效果*

- 简单的多线程服务器(后续实现线程池)

### 2. 服务器支持命令

## 四、文件组织

- StudySpace
  
  - Server
    
    - lib
      
    - include
      
    - src
      
      - server
        
        - driver.cpp
          
        - server.hpp
          
        - server.cpp
          
        - guard.hpp
          
        - guard.cpp
          
        - standard.hpp
          
        - net.hpp
          
        - net.cpp
          
      - service
        
        - service.hpp
          
        - service.cpp
          
    - test
      
  - Client
    
    - lib
      
    - doc
      
    - src
      
      - main.cpp
        
      - standard.hpp
        
      - model
        
      - view
        
      - controller
        
      - net
        

## 五、配置文件规范

- netConfig.hdat
  
  `serverhost <host>`
  
  `serverport <port>`
  

## 六、错误代码

- 网络
  
  - 10001: 套接字socket阶段问题
    
  - 10002: 套接字connect阶段问题
    
  - 10003：不能与服务器正常通信
    

## 七、服务代码

- TEST: 测试

## 八、规定

- 用户ID数字段： 10001(1e5+1) ~ 999999999999(1e13-1)
- users.hdat字段描述

`ID[KEY] USERNAME[0] PASSWORD[1] EMAIL[2] REG-YEAR[3] REG-MONTH[4] REG-DAY[5]`

## 九、相关指导

### A. 使用网络控制器中的类

*<u>参考以下四个部分</u>*

- 使用网络控制器的类的声明与定义
  
  约定需要使用网络控制器的类为netObject.
  
  - 首先，在netObject声明slot：
  
  `public slots:`
  
  `    void xxx_update();`
  
  - 然后，在netObject声明函数：
  
  `public:`
  
  `   void setupNetController()`
  
  - 接着，在netObject的定义源文件中声明全局变量
  
  `extern net::NetController* netController;//From mainwindow.cpp`
  
  - 继续，定义setupNetController()，其行为是关联网络控制器中对应的的signal和netObject中声明的网络控制槽点。
    
  - 最后，实现槽点xxx_update()；
    
- 网络控制器中的注册
  
  - 首先，在netController.cpp中为需要使用网络控制器的类注册处理函数。(xxx_handler)
    
  - 然后，在函数netControllerEntry()的定义中添加eventType匹配。
    
- 使用网络控制器的类的使用
  
  - 在MainWindow::setupNetController()中使用相应的类的setupNetController函数。
- 在服务端的service.cpp中为相应功能实现注册。
  

### B. 在MainWindow中添加页面和列表

- 在MainWindow的类声明中，在Pages, Lists, setupDelegate() 和 public slots:中注册。

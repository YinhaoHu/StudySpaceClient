#pragma once

#include<qapplication.h>

#ifdef _CLIENT_DRIVER_
QApplication* qapplication;
#else
extern QApplication* qapplication;
#endif
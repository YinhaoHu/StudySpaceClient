#pragma once
#include"model/widget/tipwindow.hpp"

//Control
#ifndef _CLIENT_DRIVER_
extern TipWindow* tipWindow;
#else
TipWindow* tipWindow;
#endif // !_CLIENT_DRIVER_

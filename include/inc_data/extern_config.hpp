#pragma once
#include"data/config_manager.hpp"

#ifdef _CLIENT_DRIVER_
ConfigManager* config_manager;
#else
extern ConfigManager* config_manager;
#endif
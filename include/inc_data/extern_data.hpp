#pragma once

#include"data/local_datamanager.hpp"
#include"data/runtime_datamanager.hpp"

#ifdef _MAINWINDOW_
extern 
QSharedPointer<data::Runtime_DataManager> runtime_dataManager(new data::Runtime_DataManager);
#else
extern QSharedPointer<data::Runtime_DataManager> runtime_dataManager;
#endif

#ifdef _MAINWINDOW_
QSharedPointer<data::Local_DataManager> local_dataManager(new data::Local_DataManager);
#else
extern QSharedPointer<data::Local_DataManager> local_dataManager;
#endif
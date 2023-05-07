#pragma once

#include"data/studyaids/todayschedule_datamanager.hpp"

#ifdef _TODAYSCHEDULE_
data::TodayScheduleDataManager* todayScheduleDataManager;
#else 
extern data::TodayScheduleDataManager* todayScheduleDataManager;
#endif
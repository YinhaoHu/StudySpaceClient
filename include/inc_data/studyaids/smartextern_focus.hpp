#pragma once

#include"data/studyaids/focus_datamanager.hpp"

#ifdef _FOCUS_WIDGET_
data::FocusDataManager* focusDataManager;
#else
extern data::FocusDataManager* focusDataManager;
#endif
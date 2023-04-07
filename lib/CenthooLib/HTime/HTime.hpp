#if __cplusplus < 	202002L
#error "HTime is ok with cplusplus 20 or higher version"
#endif

#ifndef _HTIME_HPP_
#define _HTIME_HPP_

#define _CRT_SECURE_NO_WARNINGS

#include<ctime>

namespace ceh {
	namespace Time {
		class HTime;
	}
}

class ceh::Time::HTime {
private:
	struct tm* timeStorage;
public:
	HTime();

	 int getYearByInt();
	 void getYearByStr(char* _dest);
	 int getMonthByInt();
	 void getMonthByStr(char* _dest);
	 int getMDayByInt();
	 void getMDayByStr(char* _dest);
};

#endif
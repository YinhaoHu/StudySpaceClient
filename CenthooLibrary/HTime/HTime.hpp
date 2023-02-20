#ifndef _HTIME_HPP_
#define _HTIME_HPP_

#define _CRT_SECURE_NO_WARNINGS

#include<ctime>
#include<cstring>

#ifndef _HSTRING_HPP_
#include"../HString/HString.hpp"
#endif

namespace ceh {
	namespace Time {
		class HTime;
	}
}

class ceh::Time::HTime {
private:
	struct tm* timeStorage;
public:
	HTime() {
		time_t timeStorageT;
		timeStorage = new struct tm;

		time(&timeStorageT);
		timeStorage = gmtime(&timeStorageT);
	}

	~HTime() {
		delete timeStorage;
	}

	int getYearByInt() {
		return timeStorage->tm_year + 1900;
	}
	void getYearByStr(char* _dest) {
		char str[8];
		ceh::String::uintToStr(getYearByInt(), str);
		strncpy(_dest, str,7);
	}
	int getMonthByInt() {
		return timeStorage->tm_mon + 1;
	}
	void getMonthByStr(char* _dest) {
		char str[3];
		ceh::String::uintToStr(getMonthByInt(), str);
		strncpy(_dest, str,3);
	}
	int getMDayByInt() {
		return timeStorage->tm_mday;
	}
	void getMDayByStr(char* _dest) {
		char str[3];
		ceh::String::uintToStr(getMDayByInt(), str);
		strncpy(_dest, str, 3);
	}
	int getHourByInt() {
		return timeStorage->tm_hour;
	}
	void getHourByStr(char* _dest)
	{
		char str[3];
		ceh::String::uintToStr(getHourByInt(), str);
		strncpy(_dest, str,3);
	}
	int getMinByInt() {
		return timeStorage->tm_min;
	}
	void getMinByStr(char* _dest) {
		char str[3];
		ceh::String::uintToStr(getMinByInt(), str);
		strncpy(_dest, str, 3);
	}
	int getSecByInt() 
	{
		return timeStorage->tm_sec;
	}
	void getSecByStr(char* _dest) {
		char str[3];
		ceh::String::uintToStr(getSecByInt(), str);
		strncpy(_dest, str, 3);
	}
};

#endif
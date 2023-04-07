#include"HTime.hpp"

#include<format>

#include<ctime>

using namespace ceh::Time;
using namespace std;

HTime::HTime() {
	time_t timeStorageT;

	time(&timeStorageT);
	timeStorage = gmtime(&timeStorageT);
}


 int HTime::getYearByInt() {
	return timeStorage->tm_year + 1900;
}
 void HTime::getYearByStr(char* _dest) {
	strcpy(_dest, format("{}",getYearByInt()).c_str());
}
 int HTime::getMonthByInt() {
	return timeStorage->tm_mon + 1;
}
 void HTime::getMonthByStr(char* _dest) {
	strcpy(_dest, format("{}", getMonthByInt()).c_str());
}
 int HTime::getMDayByInt() {
	return timeStorage->tm_mday;
}
 void HTime::getMDayByStr(char* _dest) {
	strcpy(_dest, format("{}", getMDayByInt()).c_str());
}
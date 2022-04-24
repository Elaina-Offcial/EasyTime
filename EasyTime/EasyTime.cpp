#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <thread>
#include <sstream>
#include "EasyTime.h"
using namespace EasyTime;
using namespace std::chrono;

EasyTime::Clock::Clock() : year("1970"), month("01"), day("01"), hour("00"), minute("00"), second("00"), millisecond("000"), microsecond("000000"), nanosecond("000000000")
{

}

EasyTime::Clock::Clock(const sys_time<nanoseconds> systime, const string Year, const string Month, const string Day, const string Hour, const string Minute, const string Second, const string Millisecond, const string Microsecond, const string Nanosecond) : SysTime(systime), year(Year), month(Month), day(Day), hour(Hour), minute(Minute), second(Second), millisecond(Millisecond), microsecond(Microsecond), nanosecond(Nanosecond)
{

}

EasyTime::Clock::Clock(const Clock &time): SysTime(time.SysTime), year(time.year), month(time.month), day(time.day), hour(time.hour), minute(time.minute), second(time.second), millisecond(time.millisecond), microsecond(time.microsecond), nanosecond(time.nanosecond)
{

}

string EasyTime::Clock::get(const EasyTime::Resolution &r)
{
	switch (r)
	{
	case EasyTime::Resolution::Year:
		return this->year;
	case EasyTime::Resolution::Month:
		return this->month;
	case EasyTime::Resolution::Day:
		return this->day;
	case EasyTime::Resolution::Hour:
		return this->hour;
	case EasyTime::Resolution::Minute:
		return this->minute;
	case EasyTime::Resolution::Second:
		return this->second;
	case EasyTime::Resolution::Millisecond:
		return this->millisecond;
	case EasyTime::Resolution::Microsecond:
		return this->microsecond;
	case EasyTime::Resolution::Nanosecond:
		return this->nanosecond;
	default:
		return "wtf";
	}
}

Clock EasyTime::GetCurrentTime(const int &UTC)
{
	utc_time<nanoseconds> now = utc_clock::now();
	sys_time<nanoseconds> CurrentUTCTime = utc_clock::to_sys(now);
	seconds UTCs{ UTC * 3600 };
	CurrentUTCTime += UTCs;
	std::stringstream CurrentUTCTimeString;
	std::string date, time;
	CurrentUTCTimeString << CurrentUTCTime;
	CurrentUTCTimeString >> date >> time;
	EasyTime::Clock CurrentTime =
	{
		CurrentUTCTime,
		date.substr(0, 4),
		date.substr(5, 2),
		date.substr(8, 2),
		time.substr(0, 2),
		time.substr(3, 2),
		time.substr(6, 2),
		time.substr(9, 3),
		time.substr(9, 6),
		time.substr(9, 9),
	};
	return CurrentTime;
}

void EasyTime::Clock::print()
{
	std::cout << this->SysTime << std::endl;
}

void EasyTime::Clock::PrintHighResolutionTime()
{
	std::cout << this->year << "/"
			  << this->month << "/"
			  << this->day << " "
			  << this->hour << ":"
			  << this->minute << ":"
			  << this->second << "."
			  << this->nanosecond << std::endl;
}

EasyTime::Clock::~Clock()
{
	
}

void EasyTime::Clock::clear()
{
	this->SysTime-= nanoseconds{ this->SysTime.time_since_epoch() };
	this->year = "1970";
	this->month = "01";
	this->day = "01";
	this->hour = "00";
	this->minute = "00";
	this->second = "00";
	this->millisecond = "000";
	this->microsecond = "000000";
	this->nanosecond = "000000000";
}

Clock EasyTime::Clock::operator=(const Clock &time)
{
	this->SysTime = time.SysTime;
	this->year = time.year;
	this->month = time.month;
	this->day = time.day;
	this->hour = time.hour;
	this->minute = time.minute;
	this->second = time.second;
	this->millisecond = time.millisecond;
	this->microsecond = time.microsecond;
	this->nanosecond = time.nanosecond;
	return *this;
}


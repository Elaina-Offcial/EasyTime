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

EasyTime::Clock::Clock() : year("00"), month("00"), day("00"), hour("00"), minute("00"), second("00"), millisecond("000"), microsecond("000000"), nanosecond("000000000")
{

}

EasyTime::Clock::Clock(string Year, string Month, string Day, string Hour, string Minute, string Second, string Millisecond, string Microsecond, string Nanosecond) : year(Year), month(Month), day(Day), hour(Hour), minute(Minute), second(Second), millisecond(Millisecond), microsecond(Microsecond), nanosecond(Nanosecond)
{

}

string EasyTime::Clock::GetYear()
{
	return this->year;
}

string EasyTime::Clock::GetMonth()
{
	return this->month;
}

string EasyTime::Clock::GetDay()
{
	return this->day;
}

string EasyTime::Clock::GetHour()
{
	return this->hour;
}

string EasyTime::Clock::GetMinute()
{
	return this->minute;
}

string EasyTime::Clock::GetSecond()
{
	return this->second;
}

string EasyTime::Clock::GetMillisecond()
{
	return this->millisecond;
}

string EasyTime::Clock::GetMicrosecond()
{
	return this->microsecond;
}

string EasyTime::Clock::GetNanosecond()
{
	return this->nanosecond;
}

Clock EasyTime::GetCurrentTime(int UTC)
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

void EasyTime::Clock::PrintTime()
{
	std::cout << this->year << "/"
			  << this->month << "/"
			  << this->day << " "
			  << this->hour << ":"
			  << this->minute << ":"
			  << this->second << "."
			  << this->nanosecond << std::endl;
}


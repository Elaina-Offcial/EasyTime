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
using namespace std::chrono_literals;

EasyTime::TimeFrame::TimeFrame() : year("1970"), month("01"), day("01"), hour("00"), minute("00"), second("00"), millisecond("000"), microsecond("000000"), nanosecond("000000000")
{
	
}

EasyTime::TimeFrame::TimeFrame(const string Year, const string Month, const string Day, const string Hour, const string Minute, const string Second, const string Millisecond, const string Microsecond, const string Nanosecond) : year(Year), month(Month), day(Day), hour(Hour), minute(Minute), second(Second), millisecond(Millisecond), microsecond(Microsecond), nanosecond(Nanosecond)
{
	
}

EasyTime::EasyClock::EasyClock() : TimeFrame()
{
	
}

EasyTime::EasyClock::EasyClock(const std::chrono::sys_time<nanoseconds> &Systime)
{
	std::stringstream ClockStringStream;
	std::string date, time;
	ClockStringStream << Systime;
	ClockStringStream >> date >> time;
	*this =
	{
		Systime,
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
}

EasyTime::EasyClock::EasyClock(const std::chrono::sys_time<nanoseconds> &Systime, const string &Year, const string &Month, const string &Day, const string &Hour, const string &Minute, const string &Second, const string &Millisecond, const string &Microsecond, const string &Nanosecond) : systime(Systime), TimeFrame(Year, Month, Day, Hour, Minute, Second, Millisecond, Microsecond, Nanosecond)
{
	
}

EasyTime::EasyClock::EasyClock(const EasyClock &time) : systime(time.systime), TimeFrame(time.year, time.month, time.day, time.hour, time.minute, time.second, time.millisecond, time.microsecond, time.nanosecond)
{
	
}

string EasyTime::EasyClock::get(const EasyTime::Resolution &r)
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

EasyClock EasyTime::GetCurrentTime(const int &UTCzone)
{
	utc_time<nanoseconds> now = utc_clock::now();
	sys_time<nanoseconds> CurrentUTCTime = utc_clock::to_sys(now);
	seconds UTCs{ UTCzone * 3600 };
	CurrentUTCTime += UTCs;
	return EasyClock(CurrentUTCTime);
}

EasyClock EasyTime::HighResolutionStampToEasyClock(long long &Stamp)
{
	std::chrono::nanoseconds interval{ Stamp };
	std::chrono::sys_time<nanoseconds> time;
	time += interval;
	EasyTime::EasyClock clock(time);
	return clock;
}

EasyClock EasyTime::UnixStampToEasyClock(long long &UnixStamp)
{
	long long HighResolutionStamp = UnixStamp * 1000000000;
	return HighResolutionStampToEasyClock(HighResolutionStamp);
}

long long EasyTime::EasyClock::GetHighResolutionStamp()
{
	return this->systime.time_since_epoch().count();
}

void EasyTime::EasyClock::print()
{
	std::cout << this->systime << std::endl;
}

EasyTime::EasyClock::~EasyClock()
{
	
}

void EasyTime::EasyClock::clear()
{
	this->systime -= nanoseconds{ this->systime.time_since_epoch() };
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

void EasyTime::EasyClock::RefreshTimeFromSystime()
{
	std::stringstream ClockStringStream;
	std::string date, time;
	ClockStringStream << this->systime;
	ClockStringStream >> date >> time;
	*this =
	{
		this->systime,
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
}

EasyClock EasyTime::EasyClock::operator=(const EasyClock &time)
{
	this->systime = time.systime;
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

bool EasyTime::EasyClock::operator==(const EasyClock &time)
{
	return this->systime == time.systime ? true : false;
}

std::chrono::nanoseconds EasyTime::EasyClock::operator-(const EasyClock &time)
{
	return this->systime - time.systime;
}

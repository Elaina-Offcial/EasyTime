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

EasyTime::EasyClock::EasyClock()
{

}

EasyTime::EasyClock::EasyClock(const EasyClock &time) : UTCTime(time.UTCTime)
{

}

EasyTime::EasyClock::EasyClock(const std::chrono::utc_clock::time_point UTCTimePoint) : UTCTime(UTCTimePoint)
{
	
}

EasyTime::EasyClock::EasyClock(const std::chrono::utc_clock::time_point UTCTimePoint, const int UTCzone)
{
	this->UTCTime = UTCTimePoint + seconds{ UTCzone * 3600 };
}

EasyTime::EasyClock::EasyClock(const std::chrono::utc_time<nanoseconds> NanoUTCTime) : UTCTime(NanoUTCTime)
{

}

string EasyTime::EasyClock::get(const EasyTime::Resolution &r)
{
	std::stringstream ClockStringStream;
	std::string date, time;
	ClockStringStream << this->UTCTime;
	ClockStringStream >> date >> time;
	switch (r)
	{
	case EasyTime::Resolution::Year:
		return date.substr(0, 4);
	case EasyTime::Resolution::Month:
		return date.substr(5, 2);
	case EasyTime::Resolution::Day:
		return date.substr(8, 2);
	case EasyTime::Resolution::Hour:
		return time.substr(0, 2);
	case EasyTime::Resolution::Minute:
		return time.substr(3, 2);
	case EasyTime::Resolution::Second:
		return time.substr(6, 2);
	case EasyTime::Resolution::Millisecond:
		return time.substr(9, 3);
	case EasyTime::Resolution::Microsecond:
		return time.substr(9, 6);
	case EasyTime::Resolution::Nanosecond:
		return time.substr(9, 9);
	default:
		std::cout << "Error: Invalid Resolution" << std::endl; return "";
	}
}

string EasyTime::GetCurrentStringTime(const int &UTCZone)
{
	std::stringstream ClockStringStream;
	std::string date, time;
	ClockStringStream << utc_clock::now();
	ClockStringStream >> date >> time;
	return date + " " + time + "00";
}

EasyClock EasyTime::GetCurrentTime(const int &UTCzone)
{
	utc_time<nanoseconds> CurrentUTCTime = utc_clock::now();
	return EasyClock(CurrentUTCTime + seconds{ UTCzone * 3600 });
}

void EasyTime::PrintCurrentTime(const int &UTCzone)
{
	auto CurrentUTCTime = std::chrono::utc_clock::now();
	std::cout << CurrentUTCTime + seconds{ UTCzone * 3600 };
}

EasyClock EasyTime::HighResolutionStampToEasyClock(const long long &Stamp)
{
	std::chrono::utc_time<nanoseconds> time;
	return EasyTime::EasyClock(time + std::chrono::nanoseconds{ Stamp });
}

EasyClock EasyTime::UnixStampToEasyClock(const long long &UnixStamp)
{
	long long HighResolutionStamp = UnixStamp * 1000000000;//10^9
	return HighResolutionStampToEasyClock(HighResolutionStamp);
}

long long EasyTime::EasyClock::GetHighResolutionStamp()
{
	auto LeapSeconds = std::chrono::get_leap_second_info(this->UTCTime).elapsed;
	return (this->UTCTime - LeapSeconds).time_since_epoch().count();
}

long long EasyTime::EasyClock::GetUnixStamp()
{
	auto LeapSeconds = std::chrono::get_leap_second_info(this->UTCTime).elapsed;
	return (this->UTCTime - LeapSeconds).time_since_epoch().count() / 1000000000;
}

long long EasyTime::GetCurrentHighResolutionStamp()
{
	auto LeapSeconds = std::chrono::get_leap_second_info(std::chrono::utc_clock::now()).elapsed;
	return (std::chrono::utc_clock::now() - LeapSeconds).time_since_epoch().count();
}

long long EasyTime::GetCurrentUnixStamp()
{
	auto LeapSeconds = std::chrono::get_leap_second_info(std::chrono::utc_clock::now()).elapsed;
	return (std::chrono::utc_clock::now() - LeapSeconds).time_since_epoch().count() / 10000000;
}

void EasyTime::EasyClock::print()
{
	std::cout << this->UTCTime << std::endl;
}

EasyTime::EasyClock::~EasyClock()
{

}

void EasyTime::EasyClock::clear()
{
	this->UTCTime -= nanoseconds{ this->UTCTime.time_since_epoch() };
}

EasyClock EasyTime::EasyClock::operator=(const EasyClock &time)
{
	this->UTCTime = time.UTCTime;
	return *this;
}

bool EasyTime::EasyClock::operator==(const EasyClock &time)
{
	return this->UTCTime == time.UTCTime ? true : false;
}

std::chrono::nanoseconds EasyTime::EasyClock::operator-(const EasyClock &time)
{
	return this->UTCTime - time.UTCTime;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "EasyTime.h"
using namespace std;
using namespace EasyTime;
using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
static long long NanoLength = 1000000000;
time_t EasyTime::GetUnixTime(time_t HighResolutionTime)
{
    cout << "high:" << HighResolutionTime << endl;
    string StringTime = to_string(HighResolutionTime);
    string UnixTime = StringTime.substr(0, 10);
    return stoll(UnixTime);
}

time_t EasyTime::GetNanoTime(time_t HighResolutionTime)
{
    string StringTime = to_string(HighResolutionTime);
    string NanoTime = StringTime.substr(10, 9);
    return stoll(NanoTime);
    //return HighResolutionTime % NanoLength;
}

Clock EasyTime::GetCurrentTime()
{
    struct tm *time;
    using namespace std;
    time_t HighResolutionTime = std::chrono::system_clock::now().time_since_epoch().count();
    time_t UnixTime = GetUnixTime(HighResolutionTime);
    time_t NanoTime = GetNanoTime(HighResolutionTime);
    time = localtime(&UnixTime);
    Clock CurrentTime =
    {
        time->tm_year + 1900,
        time->tm_mon + 1,
        time->tm_mday,
        time->tm_hour,
        time->tm_min,
        time->tm_sec,
        NanoTime
    };
    return CurrentTime;
}

Clock EasyTime::GetCurrentTime(long long UTC)
{
    struct tm *time;
    time_t HighResolutionTime = std::chrono::system_clock::now().time_since_epoch().count();
    cout << HighResolutionTime << endl;
    time_t UnixTime = GetUnixTime(HighResolutionTime);
    time_t NanoTime = GetNanoTime(HighResolutionTime);
    time = localtime(&UnixTime);
    Clock CurrentTime =
    {
        time->tm_year + 1900,
        time->tm_mon + 1,
        time->tm_mday,
        time->tm_hour,
        time->tm_min,
        time->tm_sec,
        NanoTime
    };
    return CurrentTime;
}

Clock EasyTime::StampToTime(time_t Stamp)
{
    struct tm *time;
    time_t HighResolutionTime = Stamp;
    time_t UnixTime = GetUnixTime(HighResolutionTime);
    time_t NanoTime = GetNanoTime(HighResolutionTime);
    time = localtime(&UnixTime);
    Clock CurrentTime =
    {
        time->tm_year + 1900,
        time->tm_mon + 1,
        time->tm_mday,
        time->tm_hour,
        time->tm_min,
        time->tm_sec,
        NanoTime
    };
    return CurrentTime;
}

Clock EasyTime::StampToTime(time_t Stamp, long long UTC)
{
    struct tm *time;
    time_t HighResolutionTime = Stamp + UTC * 3600;
    time_t UnixTime = GetUnixTime(HighResolutionTime);
    time_t NanoTime = GetNanoTime(HighResolutionTime);
    time = localtime(&UnixTime);
    Clock CurrentTime =
    {
        time->tm_year + 1900,
        time->tm_mon + 1,
        time->tm_mday,
        time->tm_hour,
        time->tm_min,
        time->tm_sec,
        NanoTime
    };
    return CurrentTime;
}

void EasyTime::PrintTime(Clock Time)
{
    cout << Time.year << "/"
        << Time.month << "/"
        << Time.day << " "
        << Time.hour << ":"
        << Time.minute << ":"
        << Time.second << "."
        << Time.nanosecond << endl;
}

EasyTime::Timer::Timer() : Duration(0)
{

}

EasyTime::Timer::~Timer()
{
}

void EasyTime::Timer::begin()
{
    this->BeginPoint = chrono::steady_clock::now();
}

void EasyTime::Timer::end()
{
    this->EndPoint = chrono::steady_clock::now();
    this->Duration = this->EndPoint.time_since_epoch().count() - this->BeginPoint.time_since_epoch().count();
}

void EasyTime::Timer::clear()
{
    
}

time_t EasyTime::Timer::GetDuration()
{
    return this->Duration;
}

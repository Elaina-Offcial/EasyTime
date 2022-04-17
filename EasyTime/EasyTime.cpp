#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <thread>
#include "EasyTime.h"
using namespace std;
using namespace EasyTime;
using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
static long long NanoLength = 1000000000;
time_t EasyTime::GetUnixTime(time_t HighResolutionTime)
{
    return HighResolutionTime / NanoLength;
}

time_t EasyTime::GetNanoTime(time_t HighResolutionTime)
{
    return HighResolutionTime % NanoLength;
}

Clock EasyTime::GetCurrentTime()
{
    struct tm *time;
    using namespace std;
    time_t HighResolutionTime = std::chrono::system_clock::now().time_since_epoch().count() * 100;
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
    time_t HighResolutionTime = std::chrono::system_clock::now().time_since_epoch().count() * 100 + UTC * 3600 * NanoLength;
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
    Clock Time =
    {
        time->tm_year + 1900,
        time->tm_mon + 1,
        time->tm_mday,
        time->tm_hour,
        time->tm_min,
        time->tm_sec,
        NanoTime
    };
    return Time;
}

Clock EasyTime::StampToTime(time_t Stamp, long long UTC)
{
    struct tm *time;
    time_t HighResolutionTime = Stamp + UTC * 3600;
    time_t UnixTime = GetUnixTime(HighResolutionTime);
    time_t NanoTime = GetNanoTime(HighResolutionTime);
    time = localtime(&UnixTime);
    Clock Time =
    {
        time->tm_year + 1900,
        time->tm_mon + 1,
        time->tm_mday,
        time->tm_hour,
        time->tm_min,
        time->tm_sec,
        NanoTime
    };
    return Time;
}

Clock EasyTime::HighResolutionStampToTime(time_t HighResolutionStamp)
{
    struct tm *time;
    time_t HighResolutionTime = HighResolutionStamp * 100;
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

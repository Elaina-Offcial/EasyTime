#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
namespace EasyTime
{
    struct Clock
    {
        time_t year;
        time_t month;
        time_t day;
        time_t hour;
        time_t minute;
        time_t second;
        time_t nanosecond;
    };
    time_t GetUnixTime(time_t HighResolutionTime);
    time_t GetNanoTime(time_t HighResolutionTime);
    Clock GetCurrentTime();
    Clock GetCurrentTime(long long UTC);
    Clock StampToTime(time_t Stamp);
    Clock StampToTime(time_t Stamp, long long UTC);
    void PrintTime(Clock Time);
    class Timer
    {
    private:
        TimePoint BeginPoint;
        TimePoint EndPoint;
        time_t Duration;//ns
    public:
        Timer();
        ~Timer();
        void begin();
        void end();
        void clear();
        time_t GetDuration();
    };

}
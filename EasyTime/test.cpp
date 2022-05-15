#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <thread>
#include "EasyTime.h"
using namespace EasyTime;
using namespace std::chrono_literals;
using EasyTime::Resolution::Year;
using EasyTime::Resolution::Month;
using EasyTime::Resolution::Day;
using EasyTime::Resolution::Hour;
using EasyTime::Resolution::Minute;
using EasyTime::Resolution::Second;
using EasyTime::Resolution::Millisecond;
using EasyTime::Resolution::Microsecond;
using EasyTime::Resolution::Nanosecond;
void print(EasyClock c)
{
	std::cout << c.get(Year) << "-" << c.get(Month) << "-" << c.get(Day) << " " << c.get(Hour) << ":" << c.get(Minute) << ":" << c.get(Second) /* << "." << c.get(Nanosecond) */ << std::endl;
}
int main()
{
    EasyClock t1 = GetCurrentTime(8);
	EasyClock t2 = GetCurrentTime(8);
    nanoseconds d = t2 - t1;
    return 0;
}
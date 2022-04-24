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
using EasyTime::Resolution::Year;
using EasyTime::Resolution::Month;
using EasyTime::Resolution::Day;
using EasyTime::Resolution::Hour;
using EasyTime::Resolution::Minute;
using EasyTime::Resolution::Second;
using EasyTime::Resolution::Millisecond;
using EasyTime::Resolution::Microsecond;
using EasyTime::Resolution::Nanosecond;
void print(Clock c)
{
	std::cout << c.get(Year) << "-" << c.get(Month) << "-" << c.get(Day) << " " << c.get(Hour) << ":" << c.get(Minute) << ":" << c.get(Second) /* << "." << c.get(Nanosecond) */ << std::endl;
}
int main()
{
    Clock ct = EasyTime::GetCurrentTime(+8);
    ct.print();
    print(ct);
    //print(ct);
    //Clock ct2 = ct;
    //ct2.clear();
    //ct2.PrintTime();
    //Clock c3;
    ////c3 += 1day; 
    //c3.PrintTime();
    return 0;
}
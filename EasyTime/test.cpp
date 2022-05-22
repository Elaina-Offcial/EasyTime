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
    using std::cout;
    using std::endl;
    auto s1 = GetCurrentTime(+8);
    auto s2 = GetCurrentTime(+8);
    s1.print();
    print(s1);
    auto s3 = utc_clock::now();
    auto s4 = utc_clock::now();
    cout << s2 - s1 << endl;
    cout << s4 - s3 << endl;
    return 0;
}
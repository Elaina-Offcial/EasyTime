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
void print(Clock c)
{
	std::cout << c.GetYear() << "-" << c.GetMonth() << "-" << c.GetDay() << " " << c.GetHour() << ":" << c.GetMinute() << ":" << c.GetSecond() << std::endl;
}
int main()
{
    Clock ct = EasyTime::GetCurrentTime(+8);
    ct.PrintTime();
    print(ct);
    return 0;
}
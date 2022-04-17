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
using namespace EasyTime;
using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
int main()
{
   /* Clock TimeNow = GetCurrentTime();
    PrintTime(TimeNow);*/
    using namespace std;
    using namespace std::chrono;
    utc_time<nanoseconds> t = utc_clock::now();
    sys_time<nanoseconds> st = utc_clock::to_sys(t);
    seconds n{ 8 * 3600 };
    st += n;
    cout << st.time_since_epoch().count() << endl;
    cout << st << endl;
   /* Timer t1;
    t1.begin();
    for (int i = 0; i < 100; i++)
        std::cout << i << std::endl;
    t1.end();
    time_t time = t1.GetDuration();
    std::cout << time << std::endl;*/
    return 0;
}
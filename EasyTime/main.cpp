#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "EasyTime.h"
using namespace EasyTime;
using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
int main()
{
    //Clock TimeNow = GetCurrentTime(+8);
    //PrintTime(TimeNow);
    using namespace std;
    cout << chrono::steady_clock::now().time_since_epoch().count() << endl;
    cout << chrono::system_clock::now().time_since_epoch().count() << endl;
    cout << chrono::high_resolution_clock().now().time_since_epoch().count() << endl;
    cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() << endl;
   /* Timer t1;
    t1.begin();
    for (int i = 0; i < 100; i++)
        std::cout << i << std::endl;
    t1.end();
    time_t time = t1.GetDuration();
    std::cout << time << std::endl;*/
    return 0;
}
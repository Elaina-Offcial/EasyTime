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
using namespace std::chrono;
using std::string;
namespace EasyTime
{
	class Clock
	{
	private:
		std::string year;
		std::string month;
		std::string day;
		std::string hour;
		std::string minute;
		std::string second;
		std::string millisecond;
		std::string microsecond;
		std::string nanosecond;
	public:
		Clock();
		Clock(string Year, string Month, string Day, string Hour, string Minute, string Second, string Millisecond, string Microsecond, string Nanosecond);
		string GetYear();
		string GetMonth();
		string GetDay();
		string GetHour();
		string GetMinute();
		string GetSecond();
		string GetMillisecond();
		string GetMicrosecond();
		string GetNanosecond();
		friend Clock GetCurrentTime(int UTC);
		void PrintTime();
	};
	enum TimeResolution { year, month, day, hour, minute, second, millisecond, microsecond, nanosecond };
	Clock GetCurrentTime(int UTC);
	void PrintTime(Clock time, TimeResolution resolution);
}
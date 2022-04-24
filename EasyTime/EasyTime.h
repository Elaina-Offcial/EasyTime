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
	enum class Resolution { Year, Month, Day, Hour, Minute, Second, Millisecond, Microsecond, Nanosecond };
	class Clock
	{
	private:
		sys_time<nanoseconds> SysTime;
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
		Clock(const sys_time<nanoseconds> systime, const string Year, const string Month, const string Day, const string Hour, const string Minute, const string Second, const string Millisecond, const string Microsecond, const string Nanosecond);
		Clock(const Clock &time);
		~Clock();
		string get(const Resolution &r);
		friend Clock GetCurrentTime(const int &UTC);
		void print();
		void PrintHighResolutionTime();
		void clear();
		Clock operator=(const Clock &time);
		template <typename T> Clock operator+(duration<T> interval);
		template <typename T> Clock operator+=(const T &interval);
	};
	//enum TimeResolution { year, month, day, hour, minute, second, millisecond, microsecond, nanosecond };
	Clock GetCurrentTime(const int &UTC);

}
namespace EasyTime
{

	template<typename T>
	inline Clock EasyTime::Clock::operator+(duration<T> interval)
	{
		this->SysTime += interval;
		return *this;
	}

	template<typename T>
	Clock EasyTime::Clock::operator+=(const T &interval)
	{
		this->SysTime += interval;
		return *this;
	}
}
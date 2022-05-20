#define _CRT_SECURE_NO_WARNINGS
#ifndef EASYTIME_H_
#define EASYTIME_H_
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
using namespace std::chrono_literals;
using std::string;
//class TimeFrame
namespace EasyTime
{
	class TimeFrame
	{
	protected:
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
		TimeFrame();
		TimeFrame(const string Year, const string Month, const string Day, const string Hour, const string Minute, const string Second, const string Millisecond, const string Microsecond, const string Nanosecond);
	};
}
//class Clock
namespace EasyTime
{
	enum class Resolution { Year, Month, Day, Hour, Minute, Second, Millisecond, Microsecond, Nanosecond };
	class EasyClock : public TimeFrame
	{
	private:
		std::chrono::sys_time<nanoseconds> systime;
	public:
		EasyClock();
		EasyClock(const std::chrono::sys_time<nanoseconds> &Systime);
		EasyClock(const std::chrono::sys_time<nanoseconds> &Systime, const string &Year, const string &Month, const string &Day, const string &Hour, const string &Minute, const string &Second, const string &Millisecond, const string &Microsecond, const string &Nanosecond);
		EasyClock(const EasyClock &time);
		~EasyClock();
		string get(const Resolution &r);
		friend EasyClock GetCurrentTime(const int &UTCzone);
		long long GetHighResolutionStamp();
		void print();
		void clear();
		void RefreshTimeFromSystime();
		EasyClock operator=(const EasyClock &time);
		bool operator==(const EasyClock &time);
		std::chrono::nanoseconds operator-(const EasyClock &time);
		template <typename R, typename T> EasyClock operator+(const std::chrono::duration<R, T> &interval);
		template <typename R, typename T> EasyClock operator+=(const std::chrono::duration<R, T> &interval);
		template <typename R, typename T> EasyClock operator-(const std::chrono::duration<R, T> &interval);
		template <typename R, typename T> EasyClock operator-=(const std::chrono::duration<R, T> &interval);
	};
	EasyClock GetCurrentTime(const int &UTC);
	EasyClock HighResolutionStampToEasyClock(const long long &Stamp);
	EasyClock UnixStampToEasyClock(const long long &UnixStamp);
}
//EasyClock templates
namespace EasyTime
{
	template<typename R, typename T>
	inline EasyClock EasyTime::EasyClock::operator+(const std::chrono::duration<R, T> &interval)
	{
		return EasyClock(this->systime + interval);
	}

	template<typename R, typename T>
	EasyClock EasyTime::EasyClock::operator+=(const std::chrono::duration<R, T> &interval)
	{
		this->systime += interval;
		return *this;
	}

	template<typename R, typename T>
	inline EasyClock EasyClock::operator-(const std::chrono::duration<R, T> &interval)
	{
		return EasyClock(this->systime - interval);
	}

	template<typename R, typename T>
	inline EasyClock EasyClock::operator-=(const std::chrono::duration<R, T> &interval)
	{
		this->systime -= interval;
		return *this;
	}
}


#endif
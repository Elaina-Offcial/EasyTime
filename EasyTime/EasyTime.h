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
//class EasyClock
namespace EasyTime
{
	enum class Resolution { Year, Month, Day, Hour, Minute, Second, Millisecond, Microsecond, Nanosecond };
	class EasyClock
	{
	protected:
		std::chrono::utc_time<nanoseconds> UTCTime;
	public:
		EasyClock();
		EasyClock(const EasyClock &time);
		EasyClock(const std::chrono::utc_clock::time_point UTCTimePoint);
		EasyClock(const std::chrono::utc_clock::time_point UTCTimePoint, const int UTCzone);
		EasyClock(const std::chrono::utc_time<nanoseconds> NanoUTCTime);
		~EasyClock();
		string get(const Resolution &r);
		long long GetHighResolutionStamp();
		long long GetUnixStamp();
		void print();
		void clear();
		EasyClock operator=(const EasyClock &time);
		bool operator==(const EasyClock &time);
		std::chrono::nanoseconds operator-(const EasyClock &time);
		template <typename R, typename T> EasyClock operator+(const std::chrono::duration<R, T> &interval);
		template <typename R, typename T> EasyClock operator+=(const std::chrono::duration<R, T> &interval);
		template <typename R, typename T> EasyClock operator-(const std::chrono::duration<R, T> &interval);
		template <typename R, typename T> EasyClock operator-=(const std::chrono::duration<R, T> &interval);
	};
}
//Non-member functions
namespace EasyTime
{
	EasyClock GetCurrentTime(const int &UTC);
	EasyClock HighResolutionStampToEasyClock(const long long &Stamp);
	EasyClock UnixStampToEasyClock(const long long &UnixStamp);
	void PrintCurrentTime(const int &UTCzone);
	long long GetCurrentHighResolutionStamp();
	long long GetCurrentUnixStamp();
	string GetCurrentStringTime(const int &UTCZone);
	EasyClock GetCurrentTime(const int &UTCzone);
}
//EasyClock templates
namespace EasyTime
{
	template<typename R, typename T>
	inline EasyClock EasyTime::EasyClock::operator+(const std::chrono::duration<R, T> &interval)
	{
		return EasyClock(this->UTCTime + interval);
	}

	template<typename R, typename T>
	EasyClock EasyTime::EasyClock::operator+=(const std::chrono::duration<R, T> &interval)
	{
		this->UTCTime += interval;
		return *this;
	}

	template<typename R, typename T>
	inline EasyClock EasyClock::operator-(const std::chrono::duration<R, T> &interval)
	{
		return EasyClock(this->UTCTime - interval);
	}

	template<typename R, typename T>
	inline EasyClock EasyClock::operator-=(const std::chrono::duration<R, T> &interval)
	{
		this->UTCTime -= interval;
		return *this;
	}
}


#endif
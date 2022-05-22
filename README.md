# EasyTime项目简介

## 建立背景

- 对于C++中时间库的使用对于新手而言有些许不便，因此设立```EasyTime```来帮助快速上手C++中对于时间的操作。
- 本人在搜寻资料时许多资料曾提及使用C风格的时间函数和结构体来进行时间处理，然而却很少有关于纯C++的时间库使用教学，因此此项目也是为本人学习C++时间库而建立。
- 本项目使用了在```C++20```中引入的```C++20 chrono::utc_clock```  ，请注意使用支持C++20的编译器。
### 开发环境
- 本项目在```Windows10 21H2```环境下使用```Visual Studio 2022```开发。


## 项目内容：

### 1、类

**本项目包含以下类，且均包含在```EasyTime```命名空间下：**

- **```TimeFrame```**：基类，包含基础的时间点组成成分。
- **```EasyClock```**：时钟类，用来描述日历时间。

### 2、使用方法

#### （1）```TimeFrame```类

该类是用来构建派生类的基类，一般情况下无需直接使用。

其定义为：

```cpp
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
    //...
}
```

#### （2）```Resolution```类

枚举类，其拥有数个描述时间精度的字面值变量。

其定义为 ：

```cpp
enum class Resolution { Year, Month, Day, Hour, Minute, Second, Millisecond, Microsecond, Nanosecond };
```

#### （3）```EasyClock```类

该类是时间类，可以用来描述日历时间。使用成员函数```get()```可以方便地获取不同精度的日历时间。

其定义为：

```cpp
class EasyClock
{
	protected:
		std::chrono::utc_time<nanoseconds> UTCTime;
    public:
    	//...
}

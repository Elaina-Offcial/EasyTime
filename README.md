# EasyTime项目简介

## 建立背景

- 对于C++中时间库的使用对于新手而言有些许不便，因此设立```EasyTime```来帮助快速上手C++中对于时间的操作。

- 本人在搜寻资料时许多资料曾提及使用C风格的时间函数和结构体来进行时间处理，然而却很少有关于纯C++的时间库使用教学，因此此项目也是为本人学习C++时间库而建立。

- 本项目使用了在C++20中引入的```C++20 chrono::utc_clock```  ，请注意使用支持C++20的编译器。


## 项目内容：

### 1、类

**本项目包含以下类，且均包含在EasyTime命名空间下：**

- **TimeFrame**：基类，包含基础的时间点组成成分。
- **EasyClock**：时钟类，用来描述日历时间。其基类为TimeFrame。

### 2、使用方法

#### （1）TimeFrame类

该类是用来构建派生类的基类，一般情况下无需直接使用。

#### （2）Resolution类

枚举类，其拥有数个描述时间精度的字面值变量。

其定义为 

```cpp
enum class Resolution { Year, Month, Day, Hour, Minute, Second, Millisecond, Microsecond, Nanosecond };
```

#### （3）EasyClock类

该类是时间类，可以用来描述日历时间。其成员函数及作用描述如下：

- ```cpp
  EasyClock();//默认构造函数。
  ```


- ```cpp
  EasyClock(const sys_time<nanoseconds> &Systime);//构造函数。
  ```

- ```cpp
  EasyClock(const sys_time<nanoseconds> &Systime, const string &Year, const string &Month, const string &Day, const string &Hour, const string &Minute, const string &Second, const string &Millisecond, const string &Microsecond, const string &Nanosecond);//构造函数。
  ```

- ```cpp
  EasyClock(const EasyClock &time);//拷贝构造函数。
  ```

- ```cpp
  ~EasyClock();//默认析构函数。
  ```

- ```cpp
  string get(const Resolution &r);//获取指定时间精度数据。
  ```

- ```cpp
  friend EasyClock GetCurrentTime(const int &UTC);//友元声明。
  ```

- ```cpp
  long long GetHighResolutionStamp();//获取父级EasyClock类的高精度时间戳。
  ```

- ```cpp
  void print();//打印日历时间。
  ```

- ```cpp
  void clear();//清空日历时间，清空后时间为Unix时间戳起始时间。
  ```

- ```cpp
  EasyClock operator=(const EasyClock &time);//重载复制运算符。
  ```

- ```cpp
  template <typename R, typename T> EasyClock operator+(const std::chrono::duration<R, T> &interval);//重载加法运算符。接受一个std::chrono::daration参数进行运算。如1s，5ns等。下列重载+=、-、-=函数与此类似，故不一一解释。
  ```

- ```cpp
  template <typename R, typename T> EasyClock operator+=(const std::chrono::duration<R, T> &interval);
  ```

- ```cpp
  template <typename R, typename T> EasyClock operator-(const std::chrono::duration<R, T> &interval);
  ```

- ```cpp
  long long GetHighResolutionStamp();//获取父级EasyClock类的高精度时间戳。
  ```
  
- ```cpp
  void print();//打印日历时间。
  ```
- ```cpp
  void clear();//清空日历时间，清空后时间为Unix时间戳起始时间。
  ```
- ```cpp
  EasyClock operator=(const EasyClock &time);//重载复制运算符。
  ```
- ```cpp
  template <typename R, typename T> EasyClock operator+(const std::chrono::duration<R, T> &interval);//重载加法运算符。接受一个std::chrono::daration参数进行运算。如1s，5ns等。下列重载+=、-、-=函数与此类似，故不一一解释。
  ```
- ```cpp
  template <typename R, typename T> EasyClock operator+=(const std::chrono::duration<R, T> &interval);
  ```
- ```cpp
  template <typename R, typename T> EasyClock operator-(const std::chrono::duration<R, T> &interval);
  ```

- ```cpp
  template <typename R, typename T> EasyClock operator-=(const std::chrono::duration<R, T> &interval);
  ```

其非成员函数及作用描述如下：

- ```cpp
  EasyClock GetCurrentTime(const int &UTC);//友元函数。根据传入的时区来获取当前日历时间。
  ```

- ```cpp
  EasyClock HighResolutionStampToEasyClock(long long &Stamp);//根据高精度时间戳转换EasyClock对象。
  ```

- ```cpp
  EasyClock HighResolutionStampToEasyClock(long long &Stamp);//根据高精度时间戳转换EasyClock对象。
  ```
  

- ```cpp
  EasyClock UnixStampToEasyClock(long long &UnixStamp);//根据Unix时间戳转换EasyClock对象。
  ```


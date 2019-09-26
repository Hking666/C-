#include<iostream>
using namespace std;

#if 0
class Data
{
	//初始化列表：以一个冒号开始，接着是一个以逗号分隔的数据成员列表，
	//每个"成员变量"后面跟一个放在括 号中的初始值或表达式。

public:
	Data(int year, int month, int day) // 初始化列表，每个变量只能出现一次
		:_year(year)
		, _month(month)
		, _day(day)
		, a(10)
		, b(_year)
	{ 
		// 构造 函数体中的语句只能将其称作为赋初值，而不能称作初始化。
		//因为初始化只能初始化一次，而构造函数体内 可以多次赋值。

		_year = year;
		_month = month;
		_day = day;
		
	
	}
private:
	int _year;
	int _month;
	int _day;

	const int a ; // a 必须要要初始化，通过初始化列表对成员变量初始化

	int& b;//引用成员变量 ，必须放在初始化列表位置进行初始化

};
int main()
{
	//const int a = 10;
	system("pasue");
	return 0;
}

#endif

#if 0
class Data
{
	
	// this 指向一个已经创建好的对象,
public:
	Data(int year, int month, int day) 
		:_year(year)
		, _month(month)
		, _day(day)
		// ，_t( ) //Time类中已近显示定义了构造函数，没有默认的构造函数，报错
		,_t(19,13,56)  // 只能通过显示定义的构造函数进行初始化
	{
		_year = year;
		_month = month;
		_day = day;

	}
private:
	int _year;
	int _month;
	int _day;
	Time _t; // 类类型成员(该类没有默认构造函数)
};

class Time
{
public:
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		_hour = hour;
		_minute = minute;
		_second = second;

	}
private:
	int _hour;
	int _minute;
	int _second;

};
int main()
{
	Data d(2019,9,26);
	Data d1(2019,9,27);
	system("pause");
	return 0;
}

#endif

#if 0
class Time
{
public:
	Time(int hour = 1, int minute = 2, int second = 3) // 全缺省，默认构造函数
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		_hour = hour;
		_minute = minute;
		_second = second;

	}
private:
	int _hour;
	int _minute;
	int _second;

};

class Data
{

	// this 指向一个已经创建好的对象,
public:
	Data(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day) 
		// 此时，类类型成员(该类有默认构造函数)，可直接自行初始化
	{
		_year = year;
		_month = month;
		_day = day;

	}
private:
	int _year;
	int _month;
	int _day;
	 Time _t; // 类类型成员(该类有默认构造函数)

};
int main()
{
	Data d(2019, 9, 26);
	Data d1(2019, 9, 27);
	system("pause");
	return 0;
}

#endif

#if 0
class Data
{

public:
	Data(int year, int month, int day)
		:_year(year)
		, _day(day)
		, _month(month) //
	{
		_year = year;
		_month = day;
		_day = day;

	}

	void printData()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	Data(const Data& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{

	
	}
private:
	
	int _year;
	int _month;
	int _day;
};
int main()
{
	Data d(2019,9, 9);
	d.printData();
	Data d1(d);
	d1.printData();
	system("pause");
	return 0;
}
#endif


#if 0
class Data
{

public:
	explicit Data(int year) // 
		:_year(year)
	{
		_year = year;
		cout << this << endl;
	}

	void printData()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	Data& operator=(const Data& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		cout << this <<"="<< &d<< endl;
		return *this;
	}
private:

	int _year;
	int _month;
	int _day;
};
int main()
{
	Data d(2019);
	d.printData();
	
	// 用一个整形变量给日期类型对象赋值   
	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
	d = 2018; // 左：日期类型对象  右：整型变量
	d.printData();
	system("pause");
	return 0;
}

#endif

class Data
{

public:
	Data(int year, int month, int day)
		:_year(year)
		, _day(day)
		, _month(month) 
		, _count(0)
	{
		_year = year;
		_month = day;
		_day = day;
		_count++;
	}

	
	Data(const Data& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
		, _count(d._count)
	{

		++_count;
	}

	~Data()
	{
		_count--;
	}
private:

	int _year;
	int _month;
	int _day;
    int _count;
};

// Data总共创建了多少对象？
// 构造函数  拷贝构造函数 析构函数

// 统计有效对象的个数——计数
void Test()
{
	Data d(2019, 9, 26);
		Data d2(d);
}
int main()
{
	
	Test();
	
	system("pause");
	return 0;
}
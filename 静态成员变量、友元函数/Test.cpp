#include<iostream>
using namespace std;
class Data
{

public:
	Data(int year, int month, int day)
		:_year(year)
		, _day(day)
		, _month(month)
	{
		_year = year;
		_month = day;
		_day = day;
		_count++;
	}


	Data(const Data& d)// 初始化的是完全属于该对象的变量
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
		// ，_count(0)  错误，静态类型变量为所有对象共享
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

public: // 静态成员变量被 public修饰，在类外可以直接访问，
	static int _count;
};

int Data::_count = 0;

// Data总共创建了多少对象？
// 构造函数  拷贝构造函数 析构函数

// 统计有效对象的个数——计数
void Test()
{
	Data d(2019, 9, 26);
	Data d2(d);
	// 静态成员变量是所有类对象共享的成员变量
	// 不属于某个具体的对象
	cout << &d._count << " " << &d2._count << endl; // &d._count与&d2._count相同
	Data::_count; // // 静态成员变量是类的属性 ,可以通过 类名：：静态成员变量  直接访问

	cout << sizeof(d) << endl; //12   静态类型变量不会影响 类对象的大小；
	cout << sizeof(Data) << endl;//12  也不会影响类的大小，静态 存储位置在静态区；
}
int main()
{

	Test();

	system("pause");
	return 0;
}



#if 0 
class Data
{

public:
	Data(int year, int month, int day)
		:_year(year)
		, _day(day)
		, _month(month)
	{
		_year = year;
		_month = day;
		_day = day;
		_count++;
	}


	Data(const Data& d)// 初始化的是完全属于该对象的变量
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
		// ，_count(0)  错误，静态类型变量为所有对象共享
	{

		++_count;
	}

	~Data()
	{
		_count--;
	}

	int GetCount1() // 设置get方法，获取私有静态成员变量 _count;
	{

		return _count;
	}

	// 没有隐藏的this指针， 不能用const修饰 ， 必须通过对象调用
	static int GetCount2() // 设置 静态 get方法，获取私有静态成员变量 _count;
	{

		return _count;
	}
private:

	int _year;
	int _month;
	int _day;
	// 静态成员变量被 private 修饰，在类外不可以直接访问，
	static int _count;
};

int Data::_count = 0;

void Test()
{
	Data d(2019, 9, 26);
	Data d2(d);
	Data d3(2019, 9, 26);
	Data d4(2019, 9, 26);
	Data d5(2019, 9, 26);
	//Data::_count; 
	// cout << d.GetCount1() << endl; // 此时访问 对象名为d ，

	cout << Data::GetCount2() << endl; //可以通过 类名::函数名 ， 直接访问 静态成员函数，
}
int main()
{

	Test();

	system("pause");
	return 0;
}
#endif


#if 0
// 即使假设将 类中变量该位 public ，可以打印，却无法换行，因为无返回值count << d << endl;
//void operator<<(ostream& _cout,Data d)//2、全局函数进行运算符重载
//{
//	_cout << d._year << " " << d._month << " " << d._day; // 无法访问类中私有变量
//}
class Data
{

public:
	Data(int year, int month, int day)
		:_year(year)
		, _day(day)
		, _month(month)
	{
		_year = year;
		_month = day;
		_day = day;

	}


	Data(const Data& d)// 初始化的是完全属于该对象的变量，含this指针
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
		// ，_count(0)  错误，静态类型变量为所有对象共享
	{

	}

	~Data()
	{

	}

	ostream& operator<<(ostream& _cout)//1、在类中进行运算符重载
	{
		cout << _year << " " << _month << " " << _day;
		return _cout;
	}


private:

	int _year;
	int _month;
	int _day;

};


void Test()
{
	Data d(2019, 9, 26);

	//count << d << endl;
	d << cout << endl; //在类中进行运算符重载 与 cout<<d 相反 ， 应为第一个参数是this指针
	Data d2(d);
	Data d3(2019, 9, 26);

}
int main()
{

	Test();

	system("pause");
	return 0;
}

#endif
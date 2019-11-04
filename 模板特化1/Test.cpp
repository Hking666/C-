#include<iostream>
using namespace std;



template<class T>
T& Max(T& left, T& right)
{
	return left > right ? left : right;
}

#if 0 
template<>
char*& Max<char*>(char*& a, char*& b) //Max<char*>  函数特列化的名字
{
	if (strcmp(a, b) > 0)
	{
		return a;
	}
	else
	{
		return b;
	}

}

#endif


//Max(10, 20); // 10 , 20 是常量，引用加const
//template <class T>
//const T& Max(const T& a, const T& b)
//{
//	return a > b ? a : b;
//}
#if 0
char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}
class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year ,int month , int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}


	bool operator>(const Date& d)
	{
		return _day > d._month ? _day : d._day;
	
	}



	// 研究ostream
	friend ostream& operator<<( ostream& _cout,const Date& d)
	{
		_cout << d._year << "/" << d._month << "/" << d._day;
		return _cout;
	}
};


int  main()
{


	int a = 10;
	int b = 20;
	//Max(10, 20); // 10 , 20 是常量，引用加const

	cout<<Max(a, b)<<endl;
	cout<<Max(b, a) << endl;

	Date d1(2019, 11, 14);
	Date d2(2019, 11, 15);

	cout << Max(d1, d2) << endl;
	cout << Max(d2, d1) << endl;


	char* p1 = "wrold";
	char* p2 = "hello";

	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	system("pause");
	return 0;
}

#endif

template <class T>
void Test1(const T& p)  //const int* const p --->  
{
	*p = 100;
	int b = 200;

	p = &b;

}


int main()
{
	int a = 10;
	int* pa = &a;

	const int b1 = 10;
	int const b2 = 20;

	Test(pa); // int*

	return 0;
}
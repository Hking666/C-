#include<iostream>
using namespace std;


#if 0
class Date
{


public:
	void Set(int year , int month , int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void print()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
	int _day;
private:
	int _year;
protected:
	int _month;
};

class Time : public Date
{
public:
	void Set(int year, int month, int day  )
	{
		//_year = year;
		_month = month;
		_day = day;
	}

	void print()
	{
		cout<< " " << _month << " " << _day << endl;
	}
	int _day;
	int _sec;
private:
	int _hour;
protected:
	int _min;
};
int main()
{
	Date d1;
	Time t1;
	cout << sizeof(t1) << endl;
	t1.Set(1999, 1, 1);
	t1.print();
	
	//t1._year = 1996;
	//t1._month = 2;
	t1._day = 1;
	system("pause");
	return 0;
}

#endif



class Date
{


public:
	void SetA(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void print()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
	int _day;
private:
	int _year;
protected:
	int _month;
};

class Time : public Date
{
public:
	void SetB( int month, int day , int hour ,int min , int sec )
	{
		//_year = year; //
		_month = month;
		_day = day;
		int _hour = hour;
		int _min = min;
		int _sec = sec;
	}

	void print()
	{
		cout << " " << _month << " " << _day << endl;
	}
	int _day;
	int _sec;
private:
	int _hour;
protected:
	int _min;
};
int main()
{
	Date d1;
	Time t1;
	d1._day = 0;
	t1._day = 2;

	cout << d1._day << endl;
	d1.SetA(1999, 1, 1);
	d1.print();
	t1.SetA(1999, 2, 1);
	d1.print();
	t1.SetB(1, 1, 8,10,23);


	d1 = t1;
	//t1 = d1;
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

#if 0
class Data
{
	//��ʼ���б���һ��ð�ſ�ʼ��������һ���Զ��ŷָ������ݳ�Ա�б�
	//ÿ��"��Ա����"�����һ�������� ���еĳ�ʼֵ����ʽ��

public:
	Data(int year, int month, int day) // ��ʼ���б�ÿ������ֻ�ܳ���һ��
		:_year(year)
		, _month(month)
		, _day(day)
		, a(10)
		, b(_year)
	{ 
		// ���� �������е����ֻ�ܽ������Ϊ����ֵ�������ܳ�����ʼ����
		//��Ϊ��ʼ��ֻ�ܳ�ʼ��һ�Σ������캯������ ���Զ�θ�ֵ��

		_year = year;
		_month = month;
		_day = day;
		
	
	}
private:
	int _year;
	int _month;
	int _day;

	const int a ; // a ����ҪҪ��ʼ����ͨ����ʼ���б�Գ�Ա������ʼ��

	int& b;//���ó�Ա���� ��������ڳ�ʼ���б�λ�ý��г�ʼ��

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
	
	// this ָ��һ���Ѿ������õĶ���,
public:
	Data(int year, int month, int day) 
		:_year(year)
		, _month(month)
		, _day(day)
		// ��_t( ) //Time�����ѽ���ʾ�����˹��캯����û��Ĭ�ϵĹ��캯��������
		,_t(19,13,56)  // ֻ��ͨ����ʾ����Ĺ��캯�����г�ʼ��
	{
		_year = year;
		_month = month;
		_day = day;

	}
private:
	int _year;
	int _month;
	int _day;
	Time _t; // �����ͳ�Ա(����û��Ĭ�Ϲ��캯��)
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
	Time(int hour = 1, int minute = 2, int second = 3) // ȫȱʡ��Ĭ�Ϲ��캯��
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

	// this ָ��һ���Ѿ������õĶ���,
public:
	Data(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day) 
		// ��ʱ�������ͳ�Ա(������Ĭ�Ϲ��캯��)����ֱ�����г�ʼ��
	{
		_year = year;
		_month = month;
		_day = day;

	}
private:
	int _year;
	int _month;
	int _day;
	 Time _t; // �����ͳ�Ա(������Ĭ�Ϲ��캯��)

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
	
	// ��һ�����α������������Ͷ���ֵ   
	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
	d = 2018; // ���������Ͷ���  �ң����ͱ���
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

// Data�ܹ������˶��ٶ���
// ���캯��  �������캯�� ��������

// ͳ����Ч����ĸ�����������
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
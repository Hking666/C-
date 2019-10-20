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


	Data(const Data& d)// ��ʼ��������ȫ���ڸö���ı���
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
		// ��_count(0)  ���󣬾�̬���ͱ���Ϊ���ж�����
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

public: // ��̬��Ա������ public���Σ����������ֱ�ӷ��ʣ�
	static int _count;
};

int Data::_count = 0;

// Data�ܹ������˶��ٶ���
// ���캯��  �������캯�� ��������

// ͳ����Ч����ĸ�����������
void Test()
{
	Data d(2019, 9, 26);
	Data d2(d);
	// ��̬��Ա�����������������ĳ�Ա����
	// ������ĳ������Ķ���
	cout << &d._count << " " << &d2._count << endl; // &d._count��&d2._count��ͬ
	Data::_count; // // ��̬��Ա������������� ,����ͨ�� ����������̬��Ա����  ֱ�ӷ���

	cout << sizeof(d) << endl; //12   ��̬���ͱ�������Ӱ�� �����Ĵ�С��
	cout << sizeof(Data) << endl;//12  Ҳ����Ӱ����Ĵ�С����̬ �洢λ���ھ�̬����
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


	Data(const Data& d)// ��ʼ��������ȫ���ڸö���ı���
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
		// ��_count(0)  ���󣬾�̬���ͱ���Ϊ���ж�����
	{

		++_count;
	}

	~Data()
	{
		_count--;
	}

	int GetCount1() // ����get��������ȡ˽�о�̬��Ա���� _count;
	{

		return _count;
	}

	// û�����ص�thisָ�룬 ������const���� �� ����ͨ���������
	static int GetCount2() // ���� ��̬ get��������ȡ˽�о�̬��Ա���� _count;
	{

		return _count;
	}
private:

	int _year;
	int _month;
	int _day;
	// ��̬��Ա������ private ���Σ������ⲻ����ֱ�ӷ��ʣ�
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
	// cout << d.GetCount1() << endl; // ��ʱ���� ������Ϊd ��

	cout << Data::GetCount2() << endl; //����ͨ�� ����::������ �� ֱ�ӷ��� ��̬��Ա������
}
int main()
{

	Test();

	system("pause");
	return 0;
}
#endif


#if 0
// ��ʹ���轫 ���б�����λ public �����Դ�ӡ��ȴ�޷����У���Ϊ�޷���ֵcount << d << endl;
//void operator<<(ostream& _cout,Data d)//2��ȫ�ֺ����������������
//{
//	_cout << d._year << " " << d._month << " " << d._day; // �޷���������˽�б���
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


	Data(const Data& d)// ��ʼ��������ȫ���ڸö���ı�������thisָ��
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
		// ��_count(0)  ���󣬾�̬���ͱ���Ϊ���ж�����
	{

	}

	~Data()
	{

	}

	ostream& operator<<(ostream& _cout)//1�������н������������
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
	d << cout << endl; //�����н������������ �� cout<<d �෴ �� ӦΪ��һ��������thisָ��
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
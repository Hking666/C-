#include<iostream>
using namespace std;
 
#if 0
class Data
{
private:
	int year;
	int month;
	int day;
public :
	Data(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	bool operator>(const Data& d) // 
	{
		if ((year > d.year) || (year == d.year && month > d.month) || (year == d.year && month == d.month && day > d.day))
		{
			return  true;
		}

		return false;
	}


	bool IsGreater(const Data& a)
	{
		return (year > a.year) ||	(year == a.year && month > a.month )||(year == a.year && month == a.month && day > a.day);
	
	}
};
int main()
{
	Data d1(2019, 9, 24);
	Data d2(2019, 9, 25);
	Data d3(2020, 9, 24);

	d3 = d1; // ����ֵ �� ����������һ��Ĭ�ϵĸ�ֵ���������
	if (d1 > d2)
	{
		cout << "haha" << endl;
	}
	else
	{
		cout << "d1<=d2" << endl;
	}

	system("pause");
	return 0;

}

#endif

#if 0
class String 
{
public:    
	String(const char* str = "")    
	{
		_str = (char*)malloc(strlen(str) + 1);        
		strcpy(_str, str);
	}

	 ~String()    
	 {
	   cout << "~String()" << endl; 
				   free(_str);
	  } 

private:   
	
	char* _str;
};
// ��ֵ��������أ�����û�δ��ʽ�ṩ����������������һ��Ĭ�ϵģ���ǳ�����ķ�ʽ��
// ���һ�������漰����Դ�����û������ṩ��ֵ���������
// ��ν��ǳ���������⣿
// ��ֵ������������޷���ֵ��

void TestString()
{
	String s1("hello");
	String s2("world"); 
	s1 = s2; // s1 s2����ʹ��ͬһ���ڴ�ռ䣬ǳ������s1ԭ���Ŀռ�Ҳ�Ҳ����ˣ��ڴ�й©�ˣ�
}
int main() 
{
	TestString();
	system("pause");
	return 0;
}

#endif


#if 0
class Data
{
private:
	int year;
	int month;
	int day;
public:
	Data(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	bool operator>(const Data& d) // 
	{
		if ((year > d.year) || (year == d.year && month > d.month) || (year == d.year && month == d.month && day > d.day))
		{
			return  true;
		}

		return false;
	}


	bool IsGreater(const Data& a)
	{
		return (year > a.year) || (year == a.year && month > a.month) || (year == a.year && month == a.month && day > a.day);

	}
	
	// ��ֵ���������
	// ���޷���ֵ���� �� �����������͵ķ���ֵ��ֱ�ӷ�������
	Data& operator=(const Data& d)
	{
		if ( this != &d) // ��������Լ����Լ���ֵ������Ч��
		{
			year = d.year;
			month = d.month;
			day = d.day;
		}
		

		return *this; //���ض���*this ���� d,�������ڶ��Ⱥ������������ڳ�������*this ������������� 
	}

	// Ϊ������ �����һ������ 
	// ǰ��++
	Data& operator++() // ���ض���
	{
		day += 1;
		return *this;
	}
	
	// ���� ++
	// ���һ���������γ�����
	Data operator++( int ) // ���ض��󣬲��������� 
	{
		Data temp(*this);// ����+1 ֮ǰ��ֵ , ��ֵΪ����ջ�ϵ�һ�����󣬳������������٣�
		day += 1;
		//  ������Ϊ��������ֵ�����ܷ��غ���ջ�ϵĶ��� 
		return temp; // �����������֮ǰ�ľ�ֵ������Ҫ���ض���ֻ�ܲ�������
		
	}

	Data& operator--( )
	{
		day -= 1;
		return *this; 
	
	}

	Data operator--( int )
	{
		Data temp(*this);
		day -= 1;

		return temp;


	}

	//Data operator+(int days) // + ����ı�����������ݡ����ܷ���*this
	//{

	//	return ;
	//
	//}
	Data* operator&() 
	{
		return this;
	}


	Data* operator&() 
	{
		return this;
	}
//	const ���͵ĳ�Ա������
	//	��const ��Ա�����У������޸�����κγ�Ա��
	// �� this ָ����ָ��ռ�������ݲ����޸�
	void PrintfData()const  // const ���ε���ָ��
	{
		//day++;
		// month++;
		// this->day++; this ָ����ָ��ռ�������ݲ����޸�
		cout << year << " " << month << " " << day << endl;
	}
};


int main()
{
	Data d1(2019, 9, 24);
	Data d2(2019, 9, 25);
	Data d3(2020, 9, 24);

	d3 = d1; // ����ֵ �� ����������һ��Ĭ�ϵĸ�ֵ���������,,d3.operator= (d2)  --- operator=( &d3,&d1)
	
	d3 = d2 = d1; // 
	//d3.operator=(d2.operator=(d1));

	//����������Լ����Լ���ֵ����Ҫ��ֹ��
	d3 = d3;
	Data& d4 = d3;
	d4 = d3;

	//����++ ���������
	d2 = d3++; 
	//  �ȼ��� d2.operator=(d3.operator++())


	d2 = ++d3;
	// �ȼ��� d2.operator=(d3.operator++( ) )
	

	cout << &d1 << endl;

	const Data d4(2019, 9, 26); // const ���Ͷ��󣬳�Ա�������ܱ��޸�
	system("pause");
	return 0;

}

#endif


class Data
{
private:
	int year;
	int month;
	int day;
public:
	Data(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}

	void PrintfData() const
	{
		
		cout << year << " " << month << " " << day << endl;
	}
};

int main()
{
	 // const ���͵Ķ����ܵ�����ͨ���͵ĳ�Ա����
	// ԭ�� const���Ͷ���ĳ�Ա�����Ա��޸ģ�
	//    ��ͨ���͵ĳ�Ա�����У������޸ĳ�Ա����
	//�������������const ���͵ĺ���������ͨ���͵ĳ�Ա����������ͨ���ͳ�Ա�������ܽ�const�������ݣ���Ա�������޸� 
	const Data d1(2019, 9, 24);
	
	Data d2(2019,9,20);
	d2.PrintfData();
	system("pause");
	return 0;
}
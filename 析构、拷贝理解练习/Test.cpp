#include<iostream>
using namespace std;


class ABCD
{
public:
	
	ABCD(int a , int b ,int c)
	{

		cout << "有参构造：ABCD(int a, int b, int c) " << _a << "  " << _b << "  " << _c << endl;
		_a = a;
		_b = b;
		_c = c;
	
	}

	~ABCD()
	{
		cout << "析构函数：~ABCD()" << _a << "  " << _b << "  " << _c << endl;
	}

	int getc()
	{
		return _c;
	}
private:
	int _a;
	int _b;
	int _c;

};

class MyE
{
public:
	MyE()
		:abcd1(1,2,3)
		, abcd2(4,5,6)
		, m(100)
	{
		cout << "无参构造：MyE() " << endl;
	}

	~MyE()
	{
		cout << "析构函数：~MyE() " << endl;
	}

	MyE(const MyE& m)
		:abcd1(7, 8, 9)
		, abcd2(10, 11, 12)
		, m(100)
	{
		cout << "拷贝构造函数：MyE(const MyE& m) " << endl;
	}


	ABCD abcd1;
	ABCD abcd2;
	const int m;
};


int doingthing( MyE mye)
{
	cout << "doingthing( MyE mye)" << mye.abcd1.getc() << endl;

	return 0;
}


int run1()
{
	MyE m1;
	doingthing(m1);
	return 0;
}

int run2()
{
	printf("run2()......begin.....\n");

	ABCD(10, 20, 30);
	
	ABCD abdc1 = ABCD(40, 50, 60);

	printf("run2()......end.....\n");
	
	return 0;
}
int main()
{

	run1();

	printf("\n\n\n\n\n");

	run2();
	system("pause");
	return 0;
}
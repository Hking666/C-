#include<iostream>
using namespace std;



#if 0
class Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc()override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	int _d;
};

void TestVirtualFunc(Base* pb)
{
	pb->TestFunc();
}


int main()
{
	Base b;
	Derived d;
	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	return 0;
}

#endif








#if 0
class Base
{
public:
	virtual void TestFunc()const
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

// ������Derived�������У���������������дTestFunc���麯��
// C++98��������
// C++11:�ṩ��final�Ĺؼ��ֿ�������
// final�����麯�����������麯�����������������б���д(һ��final����������麯��)
class Derived : public Base
{
public:
	virtual void TestFunc()const override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	int _d;
};

#endif
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

// 假设在Derived的子类中，不想让其子类重写TestFunc的虚函数
// C++98中做不到
// C++11:提供的final的关键字可以作用
// final修饰虚函数，表明该虚函数不想让其在子类中被重写(一般final修饰子类的虚函数)
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
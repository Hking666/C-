#include<iostream>
using namespace std;

//如果一个类中包含有虚函数，类大小会多四个字节
//编译器会给该类生成一个默认的构造函数
class Base
{
public:
	// 	Base()
	// 	{}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	int _b;
};


int main()
{
	cout << sizeof(Base) << endl;

	Base b;
	b._b = 1;

	return 0;
}

#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	int _d;
};

typedef void(*PVFT)(); //函数指针PVFT 

void PrintTable(Base& b, const string& str)
{
	cout << str << endl;
	//&b;  // 指向对象本身
	//(int*)&b; // 指向对象的前4个字节
	//*(int*)&b; // 对象前4个字节中内容--->是整形数字

	// 将整形数字转化成表格的首地址--->需要知道表格中元素的类型--->前期已经假设表格中存储的是虚函数的地址
	PVFT* pVFT = (PVFT*)(*(int*)&b);//表格首地址

	while (*pVFT)
	{
		(*pVFT)();// 函数指针调用对应函数
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Base) << endl;

	Base b1, b2;

	Base b;
	b._b = 1;

	cout << sizeof(Derived) << endl;
	Derived d;
	d._b = 1;
	d._d = 2;

	PrintTable(b, "Base VFT:");
	PrintTable(d, "Derived VFT:");

	// 确认TestFunc4和TestFunc5的入口地址
	d.TestFunc4();
	d.TestFunc5();



	return 0;
}

#endif
#include<iostream>
using namespace std;

class Test
{
public :

	Test()
	{
		cout << "Test() 无参构造" << endl;
		_x = 0;
		_y = 0;
	}

	Test(int x ,int y)
	{
		cout << "Test(int x ,int y) 有参构造" << endl;
		_x = x;
		_y = y;
	}

	Test( const Test& t)
	{
		cout << "Test( const Test& t) 拷贝构造" << endl;
		_x = t._x;
		_y = t._y;
	
	}

	Test& operator=(const Test& t)
	{

		cout << "Test& operator=(const Test& t) 赋值运算符重载" << endl;
		_x = t._x;
		_y = t._y;
		return *this;
	}

	~Test()
	{
		cout <<this<<"~T() 析构函数" << endl;
	}


	void print()
	{
		cout << "_x = " << _x << "_y = " << _y << endl;
	}
private:
	int _x;
	int _y;
};



void test1()
{
	Test t1(10, 20);
	cout << "*****************************" << endl;
	Test t2(t1);
	cout << "*****************************" << endl;
}

void test2()
{
	Test t1(10, 20);
	cout << "*****************************" << endl;
	Test t2 = t1;
	cout << "*****************************" << endl;
}


void test3()
{
	Test t1(10, 20);
	cout << "*****************************" << endl;
	Test t2 ;
	t2 = t1;
	cout << "*****************************" << endl;
}


void func(Test t)
{
	cout << "func begin..." << endl;

	t.print();

	cout << "func end..." << endl;

}

void test4()
{
	cout << "test4() begin..." << endl;

	Test t1(10, 20);

	func(t1);

	cout << "test4() end..." << endl;

}
int main()
{
	test1();
	cout << "\n" <<"\n" << endl;
	test2();
	cout << "\n" << "\n" << endl;
	test3();
	cout << "\n" << "\n" << endl;
	test4();
	system("pause");
	return 0;
}
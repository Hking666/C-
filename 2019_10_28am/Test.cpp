#pragma warning (disable:4996)
#include<iostream>
using namespace std;
#include<string.h>
#if 0
int test(int a  ,int b)
{
	return a + b;
}

int test(int a, int b, int c = 100)
{

	return a + b + c;
}



int test(int a, int b, )
{
	return a + b;
}
int  main()
{
	//test(10,20,100);
	//test(10, 20, 30);
	//test(10,20);
	return 0;
}

#endif

#if 0
// 定义函数指针
int test(int a, int b)
{
	cout << a + b << endl;
	return 0;
}


int test1(int a, int b, int c)
{
	cout << a + b+ c<< endl;
}
// 方法一： 定义一种函数类型
typedef int(MY_TEST)(int, int);

// 方式二：定义一个函数指针
typedef int(*MY_TEST1)(int, int);

int  main()
{

	
	MY_TEST* pf = nullptr;
	pf = test;
	pf(10,20); // 函数指针时假指针 pf == *pf == ***pf
	(*pf)(10, 20);
	(*********pf)(10, 20);

	MY_TEST1 pf1 = nullptr;
	pf1 = test;
	pf1(100, 200);
	(*pf1)(100, 200);
	(*****pf1)(100, 200);

	int(*pf3)(int, int)  = nullptr;
	pf3 = test;
	(pf3)(10, 20);
	(*pf3)(10, 20);
	(****pf3)(10, 20);

	system("pause");
	return 0;
}

#endif

//
//class MyClass
//{
//public:
//	MyClass()
//	{
//		cout << "MyClass()" << endl;
//	}
//
//	~MyClass()
//	{
//		cout << "~MyClass()" << endl;
//	}
//};
//
//int main()
//{
//
//	MyClass a[4],*p[5];
//	system("pause");
//	return 0;
//}

namespace test
{
class string
{
public:
	string(char* str="")
	{
		if (nullptr == str)
		{
			str = "";
		}

		_str = (char*)malloc(sizeof(strlen(str)) + 1);

		strcpy(_str, str);
		cout << " string() " << endl;
	}

	void operator=(const string& s)
	{
	
		cout << " =string()" << endl;
		
	}

	~string(){
	
		if (_str != nullptr)
		{
			free(_str );
			_str = nullptr;
		}
		cout << "~string()" << endl;
	}
private:
	char* _str;
	
};

}


void func(test::string s)
{

}

void Test1()
{
	test::string s1;
	test::string s2(s1);
	func(s1); 
}
int main()
{
	Test1();
	return 0;
}
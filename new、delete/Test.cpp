#include<iostream>
using namespace std;



#if 0
//
//int main()
//{
//	int* p = (int*)malloc(sizeof(int)* 10);
//	free(p);
//	return 0;
//}

// new / delete     new[] / delete[]
// malloc/free
// 注意：一定要匹配使用

// 1. new和delete不是函数，C++提供的新的操作符
// 2. new/new[] 只需在其后跟空间类型，不需要传递字节数
// 3. new 后跟的就是空间的类型，因此不需要强转
// 4. new/new[]可以进行初始化
// 5. new的结果不需要判空
// 6. 
int main()
{
	int arr[10]; // 类型 ： int[10]
	// new 申请单个类型元素的空间---默认情况：new出的空间在堆上
	int*p1 = new int;
	int*p2 = new int(10); // 初始化申请空间为10

	int* p3 = new int[10];
	int* p4 = new int[10]{1,2,3,4,5,6,5,6,9,5};

	delete p1;
	delete p2;
	delete[] p3;

	return 0;
}

#endif

#if 0
//假入申请和释放不匹配 ？，
// 1、如果申请的是内置类型的空间，不会产生任何后果
int main()
{
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = (int*)malloc(sizeof(int)* 10);

	delete p1;
	delete p2;

	int*p3 = new int;
	int*p4 = new int;
	free(p3);
	delete[] p4;


	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;

	_CrtDumpMemoryLeaks();
	return 0;
}

#endif


#if 0
// 2、对于自定义类型对象
class Test
{
public:
	Test()
	{
		_data = 10;
		_p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
	int* _p;
};

// 对于自定义类型，只要涉及到[]，必然会崩溃
// new会调用构造函数
// free不会调用析构函数--对象中的资源不会被销毁
void Test2()
{
	//Test* p3 = new Test;
	//Test* p4 = new Test;
	//free(p3);
	//delete[] p4;


	// malloc申请空间时不会调用构造函数--申请的是与对象大小相同的一块内存空间
	//             不能讲该块内存空间看成是一个对象

	Test* p1 = (Test*)malloc(sizeof(Test));
	//Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;   // 需要调用析构函数清理对象中的资源
	//delete[] p2;



	//Test* p5 = new Test[10];
	//Test* p6 = new Test[10];
	//free(p5);
	//delete p6;
}

int main()
{
	//Test1();
	Test2();
	_CrtDumpMemoryLeaks();
	return 0;
}

#endif


#if 0
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt1 = new Test; //先申请空间再调用构造函数
	 
	Test* pt2 = new Test[10];
	delete pt1;
	delete[] pt2;
	return 0;
}

#endif


void* operator new(size_t size)
{

	return malloc(size);
}
int main()
{
	int* p = new int;
	delete(p);
	return 0;
}
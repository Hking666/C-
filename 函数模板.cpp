
#if 0
// 64位系统 & 程序按照64位方式编译---指针就是8个字节
#include <iostream>
using namespace std;

int main()
{
	cout << sizeof(int*) << endl;
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

#if 0
// 写一个通用的加法函数？--任意类型都可以处理
// 函数重载
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}


int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif

#if 0
// 与类型无关
// Add函数模板
//template<class T1, class T2>       // 模板参数列表
//T1 Add(T1 left, T2 right)  // 参数列表
//{
//	cout << typeid(T1).name() << endl;
//	return left + right;
//}

template<class T>       // 模板参数列表
T Add(T left, T right)  // 参数列表
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	// 对函数模板进行实例化（ 编译阶段，编译器根据实例化生成相应代码 ）
	// 在编译阶段，如果编译器检测到对某个函数模板进行了实例化
	// 1、对实参的类型进行推演，根据推演的结果，确认模板参数列表中T的实际类型
	// 2、结合函数模板生成处理具体类型的函数
	// 3、隐式实例化
	Add(1, 2);  // int, int--T==>int 生成intAdd函数--->Add<int>
	Add(1.0, 2.0); //double, double--> T==>double 生成double Add函数--->Add<double>
	Add('1', '2'); //char char-->T==char 生成char Add函数--->Add<char>
	
	// 模板参数一般不会进行类型转化
	//Add(1, 2.0);   // int double--> T
	Add(1, (int)2.0);


	// 显式实例化---直接指定参数T的实际类型
	// 编译器：可能会进隐式类型转化
	Add<int>(1, 2.0);
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(T left, T right)
{
	return left + right;
}

int main()
{
	Add(1, 2);


	// 对函数模板进行隐式实例化
	// 同名函数与函数模板同时存在时，优先使用模板生成的同名函数
	Add<>(1, 2);   


	Add<int>(1, 2);
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);

	Add(1.0, 2);
	return 0;
}
#endif

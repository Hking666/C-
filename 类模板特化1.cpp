#include<iostream>
using namespace std;

#if 1
template< class T>
const T& Max(const T& a, const T& b)
{
	return a > b ? a : b;

}
//template<>
//const char*& Max<char*>( const char*& a,const char*&  b)//  ----> const char*& p ---- char*& const p;
//{
//	if (strcmp(a, b) > 0)
//	{
//		return a;
//	}
//	return b;
//}


int main()
{ 
	const char* a = "hello";
	const char* b = "world";
	Max(a, b);
	return 0;
}

#endif

#if 0
template<class T>
void Test(const T& p) // const int*& p<---错误 int*& const p   , 表示p的指向不能修改，空间内容可以被修改
{
	*p = 100;

	int b = 20;
	//p = &b;
}

int main()
{
	int a = 10;
	int* pa = &a;

	const int b1 = 10;
	int const b2 = 20;

	Test(pa); // int*
	return 0;
}

#endif
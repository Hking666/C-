#include <iostream>

#if 0
inline auto Add(auto a, auto b )
{
	return a + b;
}

#endif

class A
{
	A()
	{}
	//auto a ;

		
};


int main()
{

	int a = 10;
	auto aa = a;
	auto ab = aa;
	auto& ac = a;
	int b[] = {1,2,3,4,5};
	//auto ba[] = { 1, 2, 3, 4, 5 };

	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
	{
		 e++;
	}

	for (auto e : array)
	{
		std::cout << e << std::endl;
	}
	return 0;
}

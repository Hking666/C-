#include<iostream>
using namespace std;

#if 0
class B
{
public:
	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	//d._b = 1;  // 菱形继承缺陷：会存在二义性问题

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
	return 0;
}
#endif

#if 0
// 菱形虚拟继承
class B
{
public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

#if 1
	D d;
	d._b = 1;  // 菱形继承缺陷：会存在二义性问题

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
#endif

	// 菱形虚拟继承

	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	return 0;
}
#endif

#if 0
// 虚拟继承
class B
{
public:
	int _b;
};

class D : virtual public B
{
public:
	int _d;
};


int main()
{
	cout << sizeof(D) << endl; //12

	D d;  //前4个字节在构造是给进
	d._b = 1;
	d._d = 2;

	return 0;
}
#endif

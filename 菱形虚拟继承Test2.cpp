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
	//d._b = 1;  // ���μ̳�ȱ�ݣ�����ڶ���������

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
	return 0;
}
#endif

#if 0
// ��������̳�
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
	d._b = 1;  // ���μ̳�ȱ�ݣ�����ڶ���������

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
#endif

	// ��������̳�

	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	return 0;
}
#endif

#if 0
// ����̳�
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

	D d;  //ǰ4���ֽ��ڹ����Ǹ���
	d._b = 1;
	d._d = 2;

	return 0;
}
#endif

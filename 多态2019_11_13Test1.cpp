#include<iostream>
using namespace std;

//���һ�����а������麯�������С����ĸ��ֽ�
//�����������������һ��Ĭ�ϵĹ��캯��
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

typedef void(*PVFT)(); //����ָ��PVFT 

void PrintTable(Base& b, const string& str)
{
	cout << str << endl;
	//&b;  // ָ�������
	//(int*)&b; // ָ������ǰ4���ֽ�
	//*(int*)&b; // ����ǰ4���ֽ�������--->����������

	// ����������ת���ɱ����׵�ַ--->��Ҫ֪�������Ԫ�ص�����--->ǰ���Ѿ��������д洢�����麯���ĵ�ַ
	PVFT* pVFT = (PVFT*)(*(int*)&b);//����׵�ַ

	while (*pVFT)
	{
		(*pVFT)();// ����ָ����ö�Ӧ����
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

	// ȷ��TestFunc4��TestFunc5����ڵ�ַ
	d.TestFunc4();
	d.TestFunc5();



	return 0;
}

#endif
#include<iostream>
using namespace std;

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class D : public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
		_d = d;
	}

	//protected:
	int _d;
};

int main()
{
	B b;
	b.SetB(10);

	D d;
	//d.SetB(10);
	d.SetD(20, 30);

	// 可以用子类对象来给基类对象进行赋值
	b = d;
	//d = b; 不能用基类对派生类赋值

	// 一个基类指针可以指向子类对象，
	// 一个子类的指针不能直接指向一个基类的对象
	B* pb = &d;

	D* pd = (D*)&b;
	pd->_d = 10;

	B& rb = d;
	//D& rd = b;

	// d = b;
	return 0;
}
#endif

#if 1
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}

	void Test(int a)
	{}

	// protected:
	char _b;
};

class D : public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
	}

	void Test()
	{}

	//protected:
	int _b;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = '1';
	d.B::_b = '2';

	d.Test(10);
	d.B::Test(10);

	d.SetD(1, 2);
	return 0;
}
#endif

#if 0
// 如果基类的构造函数是无参或者全缺省的构造函数，
// 在派生类构造函数初始化列表的位置调用或不调用都可以
// 如果用户没有调用，则编译器会默认调用
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

protected:
	int _b;
};

class D : public B
{
public:
	D()
	{
		cout << "D()" << endl;
	}

protected:
	int _d;
};

int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int b)
	{
		cout << "B()" << endl;
	}

protected:
	int _b;
};

// 如果基类的构造函数带有参数的构造函数，用户必须在
// 派生类构造函数初始化列表的位置显式调用，以完成基类
// 部分成员的初始化
class D : public B
{
public:
	D()
		: B(1)
		, _d(2)
	{
		cout << "D()" << endl;
	}

protected:
	int _d;
};

int main()
{
	D d;
	return 0;
}
#endif

class B
{
public:
	B(int b)
		: _b(b)
	{
		cout << "B()" << endl;
	}

	B(const B& b)
		: _b(b._b)
	{}

	B& operator=(const B& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}

protected:
	int _b;
};

// 如果基类的构造函数带有参数的构造函数，用户必须在
// 派生类构造函数初始化列表的位置显式调用，以完成基类
// 部分成员的初始化
class D : public B
{
public:
	D(int b, int d)
		: B(b)
		, _d(d)
	{
		cout << "D()" << endl;
	}

	D(const D& d)
		: B(d)
		, _d(d._d)
	{}

	D& operator=(const D& d)
	{
		if (this != &d)
		{
			//*this = d;
			B::operator=(d);
			_d = d._d;
		}

		return *this;
	}
protected:
	int _d;
};

int main()
{
	D d1(1, 2);
	D d2(d1);

	D d3(3, 4);
	d2 = d3;
	return 0;
}

#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

class Derived : public Base
{};

int main()
{
	// 可以验证：派生类将基类中的成员变量继承到子类中
	cout << sizeof(Derived) << endl; //12 ---> 将基类的成员变量继承到子类中

	// 验证：基类中的成员函数是否被子类继承
	Derived d;
	d.SetBase(10, 20, 30);
	d.PrintBase();//
	return 0;
}
#endif


// public继承方式：
#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// 继承权限--public
// 基类中public/protected的成员在子类中权限不变
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)
class Derived : public Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

	// 访问权限：限定该成员变量是否可以直接在类外进行调用
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pro = 10;
	}
};

int main()
{
	Derived d;
	cout << sizeof(d) << endl;

	d._pub = 10;
	// d._pro = 10;
	return 0;
}

#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// 继承方式--protected
// 基类中public的成员在子类中访问权限已经变成protected
// 基类中protected的成员在子类中访问权限不变
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)
class Derived : protected Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

	// 访问权限：限定该成员变量是否可以直接在类外进行调用
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pub = 10;
		_pro = 20;
	}
};

int main()
{
	Derived d;
	// d._pub = 10;
	return 0;
}

#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// 继承方式--private
// 基类中public的成员在子类中访问权限已经变成private
// 基类中protected的成员在子类中访问权限已经变成private
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)
class Derived : private Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

	// 访问权限：限定该成员变量是否可以直接在类外进行调用
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		// _pub = 10;
		//_pro = 20;
	}
};

int main()
{
	Derived d;
	//d._pub = 10;
	return 0;
}

#endif


class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// class 和 struct的默认继承权限
// class默认继承权限---priavet
// struct默认继承权限---public
struct Derived : Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pub = 10;
	}
};

int main()
{
	D d;
	//d._pub = 10;
	return 0;
}

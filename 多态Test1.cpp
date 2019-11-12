#include<iostream>
using namespace std;
#include<string>

#if 0
class Person
{

public:
	Person(const string& name, const string& gender, int age)
		:_name(name)
		, _gender(gender)
		, _age(age)
	{}

	void BuyTicket()
	{
		cout << "全价票"<<endl;
	}


protected:
	string _name;
	string _gender;
	int _age;
};


class Stu : public Person
{
public:
	Stu(const string& name, const string& gender, int age, const string& stuId)
		:Person( name,  gender, age)
		, _stuId(stuId)
	{}

	void BuyTicket()
	{
		cout << "半价票" << endl;
	}

protected:
	string _stuId;

};


void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

void TestBuyTicket(Stu& p)
{
	p.BuyTicket();
}


int main()
{

	Person p("Peter", "男", 18);
	Stu s("小帅", "女", 19, "1000");
	
	//s.BuyTicks();
	TestBuyTicket(p);
	TestBuyTicket(s);


	system("pause");
	return 0;
}

#endif

#if 0
class Base
{
public:

	void Test1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void Test2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void Test3(int)
	{
		cout << "Base::TestFunc3()" << endl;
	}


	virtual void Test4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	void Test5()
	{
		cout << "Base::TestFunc5()" << endl;
	}

};



class Dev : public Base
{
public:

	void Test1()
	{
		cout << "Dev::TestFunc1()" << endl;
	}

	virtual void Test2()
	{
		cout << "Dev::TestFunc2()" << endl;
	}

	void Test3( )
	{
		cout << "Dev::TestFunc3()" << endl;
	}


	void Test4()
	{
		cout << "Dev::TestFunc4()" << endl;
	}

	virtual void Test5()
	{
		cout << "Dev::TestFunc5()" << endl;
	}

	
};



void TestVirtualFunc(Base* pb) // 通过指针方式调用
{
	pb->Test1();
	pb->Test2();//多态失败，原型不一致
	pb->Test3(10); //多态失败，基类未增加virtual
	pb->Test4();
	pb->Test5();

	/*A a;
	pb->TestFunc6(a);*/
}

int main()
{
	Base b;
	Dev d;

	TestVirtualFunc(&b);
	cout << "_______________________" << endl;
	TestVirtualFunc(&d);
	system("pause");
	return 0;
}

#endif

#if 0
struct A{};
struct B :public A{};

class Base
{
public:
	
	virtual Base* TestFunc5() // 基类
	{
		cout << "Base::TestFunc5()" << endl;
		return this; // 返回基类指针
	}

	virtual A& TestFunc6(A& a)// A类与Base是不同类
	{
		cout << "Base::TestFunc6()" << endl;
		return a;
	}
};

class Derived : public Base
{
public:
	
	virtual Derived* TestFunc5()//子类
	{
		cout << "Derived::TestFunc5()" << endl;
		return this;//返回子类指针
	}

	virtual B& TestFunc6(A& a)
	{
		cout << "Derived::TestFunc6()" << endl;
		return *(new B);// B类与 Derived是不同类,继承
	}
};


void TestVirtualFunc(Base* pb) // 通过指针方式调用
{
	
	pb->TestFunc5();

	A a;
	pb->TestFunc6(a);
}

int main()
{
	Base b;
	Derived d;

	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	system("pause");
	return 0;
}

#endif



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
	system("pause");
	return 0;
}



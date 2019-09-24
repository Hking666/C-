#include<iostream>
using namespace std;
 
#if 0
class Data
{
private:
	int year;
	int month;
	int day;
public :
	Data(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	bool operator>(const Data& d) // 
	{
		if ((year > d.year) || (year == d.year && month > d.month) || (year == d.year && month == d.month && day > d.day))
		{
			return  true;
		}

		return false;
	}


	bool IsGreater(const Data& a)
	{
		return (year > a.year) ||	(year == a.year && month > a.month )||(year == a.year && month == a.month && day > a.day);
	
	}
};
int main()
{
	Data d1(2019, 9, 24);
	Data d2(2019, 9, 25);
	Data d3(2020, 9, 24);

	d3 = d1; // 对象赋值 ， 编译器生成一份默认的赋值运算符重载
	if (d1 > d2)
	{
		cout << "haha" << endl;
	}
	else
	{
		cout << "d1<=d2" << endl;
	}

	system("pause");
	return 0;

}

#endif

#if 0
class String 
{
public:    
	String(const char* str = "")    
	{
		_str = (char*)malloc(strlen(str) + 1);        
		strcpy(_str, str);
	}

	 ~String()    
	 {
	   cout << "~String()" << endl; 
				   free(_str);
	  } 

private:   
	
	char* _str;
};
// 赋值运算符重载：如果用户未显式提供，编译器将会生成一份默认的，以浅拷贝的方式，
// 如果一个类中涉及到资源管理，用户必须提供赋值运算符重载
// 如何解决浅拷贝的问题？
// 赋值运算符重载有无返回值？

void TestString()
{
	String s1("hello");
	String s2("world"); 
	s1 = s2; // s1 s2将会使用同一块内存空间，浅拷贝，s1原本的空间也找不到了，内存泄漏了，
}
int main() 
{
	TestString();
	system("pause");
	return 0;
}

#endif


#if 0
class Data
{
private:
	int year;
	int month;
	int day;
public:
	Data(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	bool operator>(const Data& d) // 
	{
		if ((year > d.year) || (year == d.year && month > d.month) || (year == d.year && month == d.month && day > d.day))
		{
			return  true;
		}

		return false;
	}


	bool IsGreater(const Data& a)
	{
		return (year > a.year) || (year == a.year && month > a.month) || (year == a.year && month == a.month && day > a.day);

	}
	
	// 赋值运算符重载
	// 有无返回值？有 ， 必须是类类型的返回值，直接返回引用
	Data& operator=(const Data& d)
	{
		if ( this != &d) // 避免对象自己给自己赋值，提升效率
		{
			year = d.year;
			month = d.month;
			day = d.day;
		}
		

		return *this; //返回对象，*this 或者 d,声明周期都比函数在生命周期长，返回*this 符合运算符含义 
	}

	// 为了重载 ，添加一个参数 
	// 前置++
	Data& operator++() // 返回对象
	{
		day += 1;
		return *this;
	}
	
	// 后置 ++
	// 多加一个参数，形成重载
	Data operator++( int ) // 返回对象，不能用引用 
	{
		Data temp(*this);// 保存+1 之前的值 , 该值为函数栈上的一个对象，出了作用域被销毁，
		day += 1;
		//  引用作为函数返回值，不能返回函数栈上的对象， 
		return temp; // 返回所保存的之前的旧值，必须要返回对象，只能不加引用
		
	}

	Data& operator--( )
	{
		day -= 1;
		return *this; 
	
	}

	Data operator--( int )
	{
		Data temp(*this);
		day -= 1;

		return temp;


	}

	//Data operator+(int days) // + 不会改变操作数的内容。不能返回*this
	//{

	//	return ;
	//
	//}
	Data* operator&() 
	{
		return this;
	}


	Data* operator&() 
	{
		return this;
	}
//	const 类型的成员函数：
	//	在const 成员函数中，不能修改类的任何成员，
	// 即 this 指针所指向空间里的内容不能修改
	void PrintfData()const  // const 修饰的是指针
	{
		//day++;
		// month++;
		// this->day++; this 指针所指向空间里的内容不能修改
		cout << year << " " << month << " " << day << endl;
	}
};


int main()
{
	Data d1(2019, 9, 24);
	Data d2(2019, 9, 25);
	Data d3(2020, 9, 24);

	d3 = d1; // 对象赋值 ， 编译器生成一份默认的赋值运算符重载,,d3.operator= (d2)  --- operator=( &d3,&d1)
	
	d3 = d2 = d1; // 
	//d3.operator=(d2.operator=(d1));

	//特殊情况：自己对自己赋值，需要禁止，
	d3 = d3;
	Data& d4 = d3;
	d4 = d3;

	//重载++ 运算符操作
	d2 = d3++; 
	//  等价于 d2.operator=(d3.operator++())


	d2 = ++d3;
	// 等价于 d2.operator=(d3.operator++( ) )
	

	cout << &d1 << endl;

	const Data d4(2019, 9, 26); // const 类型对象，成员变量不能被修改
	system("pause");
	return 0;

}

#endif


class Data
{
private:
	int year;
	int month;
	int day;
public:
	Data(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}

	void PrintfData() const
	{
		
		cout << year << " " << month << " " << day << endl;
	}
};

int main()
{
	 // const 类型的对象不能调用普通类型的成员函数
	// 原因： const类型对象的成员不可以被修改，
	//    普通类型的成员函数中，可以修改成员变量
	//如果编译器允许const 类型的函数调用普通类型的成员函数，则普通类型成员函数可能将const对象（内容）成员变量给修改 
	const Data d1(2019, 9, 24);
	
	Data d2(2019,9,20);
	d2.PrintfData();
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

#include <string>

// 买票
// 普通人
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		: _name(name)
		, _gender(gender)
		, _age(age)
	{}

	// 虚函数
	virtual void BuyTicket() // 基类必须为虚函数
	{
		cout << "全价票" << endl;
	}

protected:
	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	Student(const string& name, const string& gender, int age, int stuId)
		: Person(name, gender, age)
		, _stuId(stuId)
	{}

	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuId;
};

class Soilder : public Person
{
public:
	Soilder(const string& name, const string& gender, int age, const string& rank)
		: Person(name, gender, age)
		, _rank(rank)
	{}

	void BuyTicket()
	{
		cout << "免费" << endl;
	}

protected:
	string _rank;
};


void TestBuyTicket(Person& p) //基类引用接收参数
{
	p.BuyTicket();
}



int main()
{
	Person p("Peter", "男", 18);
	Student st("小帅", "女", 19, 1000);
	Soilder so("威武", "男", 23, "班长");

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
	return 0;
}
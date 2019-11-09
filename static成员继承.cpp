#include<iostream>
using namespace std;
#include<string>


#if 0
class Person
{
public:
	Person( char*  name , int age, double height)
		:_name(name)
		,_height(height)
		,_age(age)
	{
		cout << "Person() 构造" << endl;
	}
	void Set(char * name , double height , int age)
	{
		_name = name;
		_height = height;
		_age = age;
	}

	~Person()
	{
		cout << "~Person() 析构" << endl;
	}
	char*  _name;
protected:
	double _height;
private:
	int _age;
};

class Stu : public Person
{
public:

	Stu(char * name, double height, int age)
		:Person("lili", 18,180.5)
	{

		cout << "Stu() 构造" << endl;
	}
	void Set(char* name, double height, int age, char* id)
	{
		_name = name;
		_height = height;
		//_age = age;
		_id = id;
	}

	~Stu()
	{
		cout << "~Stu() 析构" << endl;
	}
protected:
	char* _id;
	

};

void Test()
{
	Person p("huahua", 198.0, 17);
	Stu s("lili", 198.8, 18);
}
int main()
{
	Test();
	
	system("pause");
	return 0;

}

#endif

class Person
{
public:
	Person(char*  name, int age, double height)
		:_name(name)
		, _height(height)
		, _age(age)
		
	{
		_count++;
		cout << "Person() 构造" << endl;
	}

	Person()
	{
		_count++;
	}

	Person(const Person& p)
		:_name(p._name)
		, _height(p._height)
		, _age(p._age)
	{

		_count++;
	}
	void Set(char * name, double height, int age)
	{
		_name = name;
		_height = height;
		_age = age;
	}

	~Person()
	{
		_count--;
		cout << "~Person() 析构" << endl;
	}

	void GetCount()
	{
		cout << _count << endl;
	}
	char*  _name;
protected:
	double _height;
private:
	int _age;
	static int _count;
};

class Stu : public Person
{
public:

	Stu(char * name, double height, int age)
		:Person("lili", 18, 180.5)
	{
	
		cout << "Stu() 构造" << endl;
	}
	void Set(char* name, double height, int age, char* id)
	{
		_name = name;
		_height = height;
		//_age = age;
		_id = id;
	}

	~Stu()
	{
		cout << "~Stu() 析构" << endl;
	}

protected:
	char* _id;
	

};
int Person::_count = 0;


void Test()
{
	Person p("huahua", 198.0, 17);
	Person p1("huahua", 198.0, 17);
	Person p2("huahua", 198.0, 17);
	Person p3("huahua", 198.0, 17);
	p3.GetCount();
	Person p4("huahua", 198.0, 17);
	p4.GetCount();
	Stu s("lili", 198.8, 18);
	p4.GetCount();
}
int main()
{
	Test();
	Person p5("huahua", 198.0, 17);
	p5.GetCount();
	system("pause");
	return 0;

}

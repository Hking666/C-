#include<iostream>
using namespace std;

// int _age= 10; 不能再头文件中定义全局变量
class Person
{
public:
	void SetPerson(char* name, char* gender, int age);
	void PrintPersonInfo();
	//void PrintPersonInfo1(...);

private:
	char _name[20];
	char _gender[3];
	int _age;

};


// 此时这些函数会被当做全局函数对待，所以无法识别是这些类中的成员变量
// 需要加上 类名 限定符 ，让编译器识别这些函数是 成员函数
void Person::SetPerson(char* name, char* gender, int age)// this指针本质上其实是一个成员函数的形参
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;

}

//是对象调用成员函数时，将对象地址作为实参传递给this
//形参。所以对象中不存储this指针。
void Person::PrintPersonInfo()// this指针本质上其实是一个成员函数的形参
{
	cout << "我就是this：" << " " << this << endl;
	cout << _name << " " << _gender << " " << _age << endl;
}

int main()
{

	Person p;
	p.SetPerson("lili", "男", 19);
	p.PrintPersonInfo();
	return 0;
}
#include <iostream>
using namespace std;

#include <string>

// ��Ʊ
// ��ͨ��
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		: _name(name)
		, _gender(gender)
		, _age(age)
	{}

	// �麯��
	virtual void BuyTicket() // �������Ϊ�麯��
	{
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
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
		cout << "���" << endl;
	}

protected:
	string _rank;
};


void TestBuyTicket(Person& p) //�������ý��ղ���
{
	p.BuyTicket();
}



int main()
{
	Person p("Peter", "��", 18);
	Student st("С˧", "Ů", 19, 1000);
	Soilder so("����", "��", 23, "�೤");

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
	return 0;
}
#include<iostream>
using namespace std;

// int _age= 10; ������ͷ�ļ��ж���ȫ�ֱ���
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


// ��ʱ��Щ�����ᱻ����ȫ�ֺ����Դ��������޷�ʶ������Щ���еĳ�Ա����
// ��Ҫ���� ���� �޶��� ���ñ�����ʶ����Щ������ ��Ա����
void Person::SetPerson(char* name, char* gender, int age)// thisָ�뱾������ʵ��һ����Ա�������β�
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;

}

//�Ƕ�����ó�Ա����ʱ���������ַ��Ϊʵ�δ��ݸ�this
//�βΡ����Զ����в��洢thisָ�롣
void Person::PrintPersonInfo()// thisָ�뱾������ʵ��һ����Ա�������β�
{
	cout << "�Ҿ���this��" << " " << this << endl;
	cout << _name << " " << _gender << " " << _age << endl;
}

int main()
{

	Person p;
	p.SetPerson("lili", "��", 19);
	p.PrintPersonInfo();
	return 0;
}
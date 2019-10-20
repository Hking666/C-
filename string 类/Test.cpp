#include<iostream>
using namespace std;

#include<string>

void TestString()
{
	string s1;  //�ײ���һ����̬���� ��16���ֽڵĿռ䣬���� '\0'һ���ֽ�, 
	string s2("hello");
	string s3(10,'$');
	string s4(s3);

	// ������ֱ����cout��ӡ�ַ�����
	cin >> s1;
	cin >> s2;//���¸�д�ַ�����
	cout << s1 << endl;
	cout << s2 << endl; 
	
	cout << s3 << endl;
	cout << s4 << endl;
}

void TestString1()
{

	string s("1234567890123456"); 
	cout << s.length() << endl;//16

	cout << s.size()<< endl; //16 ��Ч�ַ�����������������������һ��
	cout << s.capacity() << endl; //31 �ַ����ײ�ռ�����


	
	// ֻ���string������Ч�ַ�����������ı�ײ�ռ���ܴ�С
	s.clear();

	cout << s.length() << endl;//0
	cout << s.capacity() << endl;//31

	if (s.empty())
		cout << "NULL String" << endl;
	else
		cout << "Not NULL String " << endl;
	


}


// resize / reserve
// void resize(size_t n, char ch): 
//   ����--��string���е���Ч�ַ��ı䵽n��������ַ�����ch�������
// ע�⣺ 1. ����ǽ�string���е���ЧԪ����С��ֻ�ı���ЧԪ�ظ���������ı�ײ�ռ��С
//       2. ����ǽ�string���е���ЧԪ�����࣬������Ҫ����
void TestString2()
{

	string s("123");
	cout << s << endl;//123
	cout << s.size()<< endl; //3
	cout << s.capacity() << endl; //15

	s.resize(10,'!');
	cout << s << endl;//123!!!!!!!
	cout << s.size() << endl;//10
	cout << s.capacity() << endl;//15


	s.resize(20, '#');//
	cout << s << endl;//123!!!!!!!##########
	cout << s.size() << endl;//20
	cout << s.capacity() << endl;//31

	s.resize(6);
	cout << s << endl;//123!!!
	cout << s.size() << endl;//6
	cout << s.capacity() << endl;//31

}



// void reserve(size_t newcapacity): ����
// newcapacity > oldcapacity(string��ɿռ��С)���ռ�����--->�����ı�(����������С >= newCapacity)����ЧԪ�ظ�������
// newcapacity < oldcapacity(string��ɿռ��С)���ռ���С���ú���ֱ�ӷ��� ����newcapacity < 15 
// ע�⣺ֻ�ı�������С������ı���ЧԪ�ظ���
void TestString3()
{

	string s("hello");
	cout << s.size() << endl; //
	cout << s.capacity() << endl; //

	s.reserve(10);
	cout << s.size() << endl; //
	cout << s.capacity() << endl; //

	s.reserve(20);
	cout << s.size() << endl; //
	cout << s.capacity() << endl; //

	s.reserve(40);
	cout << s.size() << endl; //
	cout << s.capacity() << endl; //

}


void TestString4()
{

	string s("asdfghjkl");
	cout << s[0] << endl;
	s[0] = 'H';

	//s[10] = '$'; Խ��--- assert����������������

	cout << s.at(2) << endl;
	s.at(2) = 'D';
	cout << s << endl;

	//s.at(10) = '$' ,Խ���쳣---�׳��쳣

}

void TestString5()
{

	string s1("asdfghjkl");
	s1.push_back('q');//asdfghjklq
	s1 += " love ";
	
	string s2("you");
	s1 += s2;

	cout << s1 << endl;//asdfghjklq love you

	s1.append(1,'H'); //asdfghjklq love youH ׷�ӵ����ַ�
	cout << s1 << endl;
	s1.append(5, 'p');//asdfghjklq love youHppppp ׷�Ӷ���ַ�
	cout << s1 << endl;
	s1.append("China");
	cout << s1 << endl;//asdfghjklq love youHpppppChina  ׷��һ���ַ���

}


// 1. string������ݻ���---vs--PJ  1.5��
//                      linux--SGI 2��
// 2. �����ǰ֪�����Ҫ��string���Ŷ��ٸ�Ԫ�أ�������ǰͨ��reserve���ռ��ṩ��
void TestPushBack()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
//
//string& insert(size_t pos, const string& str);

//string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);

//string& insert(size_t pos, const char* s);

//string& insert(size_t pos, const char* s, size_t n);

//string& insert(size_t pos, size_t n, char c);
//void insert(iterator p, size_t n, char c);

//iterator insert(iterator p, char c);

//template <class InputIterator>
//void insert(iterator p, InputIterator first, InputIterator last);

void TestString6()
{
	string s("12345");
	// c_str( ) �����ַ����� �ַ����ռ���Ƕ��׵�ַ��Ҳ���ǽ��ַ������з��� �� ���� const char*
	// atoi(s) // ����sΪ�� ��
	int ret = atoi(s.c_str()); // ��c��ʽ�ַ���ת��������
	int ret1 = atoi((char*)s.c_str()); // ����Ҫ���᲻ͬ���ͣ� Ҳ���Խ�const char* ǿתΪ char*


}

void TestString7()
{

	string s("Hello World");
	size_t pos = s.find(' ');// �������޿ո�,���ص�һ�γ��ֵ�λ��

	if (pos != string::npos)
		cout << ' ' << "is in" << pos << endl;

	pos = s.find("World");
	if (pos != string::npos)
		cout << "World" << "is in" << pos << endl;


	//// ��ȡ�ļ��ĺ�׺ - 20190923.cpp.cpp
	string s1("20190923.cpp.cpp");

	pos = s1.rfind('.')+1; // �ҵ����һ�����λ�ã���һ���ַ�

//string substr (size_t pos = 0, size_t len = npos) const;
	string filepox = s1.substr(pos);//��pos λ�ý�ȡ�ַ�����ĩβ
	cout << filepox << endl;



}

void TestString8()
{

	string s("hello");

	for (auto e : s) //��Χfor c++11
		cout << e;

	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;

	// char* ָ�� c++98
	string::iterator it = s.begin(); // ������
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	// c++11
	auto it1 = s.begin(); // ������
	while (it1 != s.end())
	{
		cout << *it1;
		++it1;
	}
	cout << endl;

}


void reverseString(string& s)
{
	char* begin = (char*)s.c_str();
	char* end = begin + s.size() - 1;//begin�Ѿ����ַ������׵�ַ������size֮�󣬾���
	cout << s[ s.end + 1];
	while (begin < end)
	{
		swap(*begin, *end);
		begin++, end--;
	}
}
int main()
{
	//TestString();
	//TestString1();
	//TeststString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString7();
	//TestString8();
	string s("123456");
	reverseString(s);
	cout << s << endl;
	system("pause");
	return 0;
}
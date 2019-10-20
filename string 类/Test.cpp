#include<iostream>
using namespace std;

#include<string>

void TestString()
{
	string s1;  //底层有一个静态数组 ，16个字节的空间，加上 '\0'一个字节, 
	string s2("hello");
	string s3(10,'$');
	string s4(s3);

	// 可以最直接用cout打印字符串，
	cin >> s1;
	cin >> s2;//重新改写字符串；
	cout << s1 << endl;
	cout << s2 << endl; 
	
	cout << s3 << endl;
	cout << s4 << endl;
}

void TestString1()
{

	string s("1234567890123456"); 
	cout << s.length() << endl;//16

	cout << s.size()<< endl; //16 有效字符个数，与其他的容器保持一致
	cout << s.capacity() << endl; //31 字符串底层空间容量


	
	// 只清空string类中有效字符个数，不会改变底层空间的总大小
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
//   功能--将string类中的有效字符改变到n个，多的字符采用ch进行填充
// 注意： 1. 如果是将string类中的有效元素缩小，只改变有效元素个数，不会改变底层空间大小
//       2. 如果是将string类中的有效元素增多，可能需要扩容
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



// void reserve(size_t newcapacity): 扩容
// newcapacity > oldcapacity(string类旧空间大小)：空间增多--->容量改变(最终容量大小 >= newCapacity)，有效元素个数不变
// newcapacity < oldcapacity(string类旧空间大小)：空间缩小，该函数直接返回 除非newcapacity < 15 
// 注意：只改变容量大小，不会改变有效元素个数
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

	//s[10] = '$'; 越界--- assert触发，引起代码崩溃

	cout << s.at(2) << endl;
	s.at(2) = 'D';
	cout << s << endl;

	//s.at(10) = '$' ,越界异常---抛出异常

}

void TestString5()
{

	string s1("asdfghjkl");
	s1.push_back('q');//asdfghjklq
	s1 += " love ";
	
	string s2("you");
	s1 += s2;

	cout << s1 << endl;//asdfghjklq love you

	s1.append(1,'H'); //asdfghjklq love youH 追加单个字符
	cout << s1 << endl;
	s1.append(5, 'p');//asdfghjklq love youHppppp 追加多个字符
	cout << s1 << endl;
	s1.append("China");
	cout << s1 << endl;//asdfghjklq love youHpppppChina  追加一个字符串

}


// 1. string类的扩容机制---vs--PJ  1.5倍
//                      linux--SGI 2倍
// 2. 如果提前知道大概要往string类存放多少个元素，可以提前通过reserve将空间提供好
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
	// c_str( ) 返回字符串类 字符串空间的那段首地址，也就是将字符串进行返回 ， 返回 const char*
	// atoi(s) // 错误，s为类 ，
	int ret = atoi(s.c_str()); // 将c格式字符串转化到整型
	int ret1 = atoi((char*)s.c_str()); // 若需要返会不同类型， 也可以将const char* 强转为 char*


}

void TestString7()
{

	string s("Hello World");
	size_t pos = s.find(' ');// 查找有无空格,返回第一次出现的位置

	if (pos != string::npos)
		cout << ' ' << "is in" << pos << endl;

	pos = s.find("World");
	if (pos != string::npos)
		cout << "World" << "is in" << pos << endl;


	//// 获取文件的后缀 - 20190923.cpp.cpp
	string s1("20190923.cpp.cpp");

	pos = s1.rfind('.')+1; // 找到最后一个点的位置，下一个字符

//string substr (size_t pos = 0, size_t len = npos) const;
	string filepox = s1.substr(pos);//从pos 位置截取字符串到末尾
	cout << filepox << endl;



}

void TestString8()
{

	string s("hello");

	for (auto e : s) //范围for c++11
		cout << e;

	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;

	// char* 指针 c++98
	string::iterator it = s.begin(); // 迭代器
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	// c++11
	auto it1 = s.begin(); // 迭代器
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
	char* end = begin + s.size() - 1;//begin已经是字符串的首地址，加上size之后，就是
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
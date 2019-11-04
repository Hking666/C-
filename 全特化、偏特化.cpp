#include<iostream>
using namespace std;


#if 0
template<class T1 , class T2>
class Date
{
private:
	T1 _d1;
	T2 _d2;


public:
	Date()
	{

		cout << " Date< T1,  T2>" << endl;
	}


};

template<>
class Date<int, int> //特化类型
{
private:
	int _d1;
	int _d2;


public:
	Date()
	{
	
		cout << " Date<int, int>" << endl;
	}


};

int  main()
{

	Date<int ,int> d1; // 调用特化
	Date<double, int> d2;  // 调用模板
	system("pause");
	return 0;

}

#endif

#if 0
template<class T1 , class T2>
class Date
{
private:
	T1 _a;
	T2 _b;

public:
	Date()
	{
	
		cout << "Date < T1,T2>";
	}

};

template<class T1>
class Date<T1,int>
{

private:
	T1 _a;
	int _b;

public:
	Date()
	{

		cout << "Date < T1,int>" <<endl;
	}


};

int  main()
{

	Date<int, int> d1; // 调用特化
	Date<double, int> d2;  // 调用模板
	system("pause");
	return 0;

}

#endif


template<class T1 , class T2>
class Date
{


private:
	T1 _a;
	int _b;

public:
	Date()
	{

		cout << "Date < T1,T2>" << endl;
	}

};

template<class T1,class T2>
class Date<T1* , T2*> 
{
public:
	Date()
	{

		cout << " Date<T1* , T2*> " << endl;
	}


private:
	T1* a;
	T2* b;
};


int  main()
{

	Date<int*, int*> d1; // 调用特化
	Date<double, int*> d2;  // 调用模板
	system("pause");
	return 0;

}
#include<iostream>
using namespace std;

class B
{
public:
	
	
	int _b;
};

class D :virtual public B
{
public:
	
	

	int _d;
};


class C :virtual public B
{
public:


	int _c;
};

class E :public D ,  public C
{
public:


	int _E;
};
int  main()
{
	
	cout << sizeof(B)<<endl; //4
	cout << sizeof(D)<<endl;//12
	cout << sizeof(C) << endl;//12
	cout << sizeof(E) << endl;//12
	D d1;//
	//d1.B::_name =1;
	//d1._id =2;
	system("pause");
	return 0;
}
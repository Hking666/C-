#include<iostream>
using namespace std;

class Test1
{

public :
	Test1()
		:_data(0)
	{
		cout << "Test()" << this << endl;
	}

private:
	int _data;

};

void Test2()
{
	Test1* p1 = (Test1*)malloc(sizeof(Test1));
	free(p1);

	Test1* p2 = (Test1*)malloc(sizeof(Test1)*20);
	free(p2);
}
void Test3()
{
	Test1* p1 = new Test1;
	delete p1;

	Test1* p2 = new Test1[10];
	delete[] p2;
}
int  main()
{
	Test2();
	Test3();
	return 0;
}
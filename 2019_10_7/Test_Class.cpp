#include <iostream>
using namespace std;

class D
{

private:
	int a;

	
public:
	double b;
private:
	int c;
public:
	int d;

	D(int _a, int _b)
	{
		a = _a;
		b = _b;
	}

	D()
		:D(0, 0)
	{
	}
	


public:
	void printA()
	{
		cout << "printA" << endl;
	}
	/*virtual void printB()
	{
		cout << "printB" << endl;
	}*/
	void GetA()
	{
		cout << &a << endl;
	}

	void GetC()
	{
		cout << &c << endl;
	}

	static void printC()
	{
		cout << "printC" << endl;
	}
};
int main(void)
{
	D *d = NULL;
	d->printA();
	d->printC();
	//d->printB();
	D dd;
	dd.GetA();
	cout << &dd.b << endl;
	dd.GetC();
	cout << &dd.d << endl;


	system("pause");
}

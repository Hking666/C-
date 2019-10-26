#include<iostream>
#pragma warning (disable:4996)
using namespace std;

void test1(int* const p)
{
	*p = 30;
}

void test2(int& p)
{
	p = 30;
}

struct Stu
{
	int id;
	char name[20] ;

};
void test3(struct Stu*&  s) 
{
	s = (struct Stu*)malloc(sizeof(struct Stu));
	if (s == nullptr)
	{
		return ;
	}
	s->id = 20;
	strcpy(s->name, "lili");

	free(s);
}


int main()
{
	const int a = 10;
	int b = 20;
	int *p =(int *) &a;
	printf("%p\n",&a);
	printf("%p\n", p);

	int arr[a] = { 1, 2, 3, 4, 5 };

	const int& aa = a;
	 int& bb = b;

	 test1(&b);
	 test2(b);
	 cout << sizeof(char&) << endl;
	 cout << sizeof(int&) << endl;
	 cout << sizeof(double&) << endl;

	 struct Stu* s1 = NULL;
	 test3(s1);
	 cout << s1->id << endl;
	 cout << s1->name << endl;
	system("pause");
	return 0;
}
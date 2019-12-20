#include <iostream>
using namespace std;
#include <windows.h>


template <class T>
class SmartPtr
{
public:
	SmartPtr(T *ptr = nullptr)
		:_ptr(ptr)
		, _owner(false)
	{
		_owner = true;
		cout << "SmartPtr(T *ptr = nullptr)" << endl;
	}

	SmartPtr(SmartPtr<T>& p)
		:_ptr(p._ptr)
		, _owner(p._owner)
	{

			p._owner = false;

	}

	~SmartPtr()
	{
		if (_ptr && _owner)
		{

			delete _ptr;
			_ptr = nullptr;
		}
		cout << "~SmartPtr()" << endl;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	SmartPtr<T>& operator=(SmartPtr<T>& p)
	{
		if (this != &p)
		{
			if (_ptr )
			{
				delete _ptr;
			}
			_ptr = p._ptr;
			_owner = p._owner;
			p._owner = false;

		}

		return *this;
	}

	
private:
	T* _ptr;
	mutable bool _owner;
};

class Person
{
public:
	char name[32];
	int age;

};
void TestSmartPtr()
{
	SmartPtr<int> ip(new int);
	SmartPtr<int> ip1(ip);
	SmartPtr<int> ip2(ip);
	ip = ip1;
	*ip1 = 100;
	*ip2 = 100;

	SmartPtr<int> ip3 = ip;
	//*ip = 10;
	//int a = *ip;
	//SmartPtr<Person>  p(new Person);
	//p->age;
}
int main()
{

	int *p = new int;
	*p = 10;

	int& n = *p;
	TestSmartPtr();
 
	
	system("pause");
	return 0;
}
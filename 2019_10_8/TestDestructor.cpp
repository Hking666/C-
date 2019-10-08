#include <iostream>
using namespace std;
#pragma warning(disable:4996)
namespace Huang
{

	class String
	{
	public:
		String(const char* str = "jack")
		{
			_str = (char*)malloc(sizeof(str)+1);
			strcpy(_str,str);
		}

		~String()
		{
			if (_str)
			{
				cout << "~String()" << endl;
				free(_str);
			}
		}
	private:
		char* _str;
	};
}


class Person
{
private:
	Huang::String _name;
	int _age;

};

int main()
{

	Person p;

	return 0;
}
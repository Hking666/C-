#include <iostream>
using namespace std;

namespace huang
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr )
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			_pCount = new int(1);
		}

		~shared_ptr()
		{
			if (_ptr && 0 == --_pCount)
			{
				delete _ptr;
				delete _pCount;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)
				++*_pCount;
			 
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
			
				if (_ptr && 0 == --*_pCount)
				{
					delete _ptr;
					delete _pCount;

				}
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
					++*_pCount;
			}

			return *this;
		}

		int use_count()
		{
			return *_pCount;
		}
	private:
		T* _ptr;
		int* _pCount;
	};
}

void Testshared_ptr()
{
	huang::shared_ptr<int> sp1(new int);
	cout << sp1.use_count() << endl;
	huang::shared_ptr<int> sp2(sp1); 
	cout << sp2.use_count() << endl;
	
	huang::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;
	huang::shared_ptr<int> sp4(sp3);
	cout << sp4.use_count() << endl;
	cout << sp3.use_count() << endl;

	sp3 = sp2;
	cout << sp3.use_count() << endl;
	sp2 = sp4;
	cout << sp2.use_count() << endl;
	cout << sp4.use_count() << endl;
}
int main()
{

	Testshared_ptr();
	return 0;
}
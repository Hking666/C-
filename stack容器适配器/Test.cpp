#include<iostream>
using namespace std;
#include<deque>


namespace bit
{
	template<class T , class Container = deque<int> >  //底层使用的是 deque
	class stack
	{
	public:
		stack()
		{ }

		void push(const T& s)
		{
		
			_con.push_back(s);

		}

		void pop()
		{
			_con.pop_back();
		}


		size_t size()const
		{
			return _con.size();
		}

		T& top()
		{
		
			return _con.back();
		}

		const T& top()const
		{
			
			return _con.back();
		}
	private:
		Container _con;
	};

}


#include<vector>

int main()
{
	bit::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.size() << endl;
	cout << s1.top() << endl;

	s1.pop();
	s1.pop();
	cout << s1.size() << endl;
	cout << s1.top() << endl;

	bit::stack<int, vector<int>> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	cout << s2.size() << endl;
	cout << s2.top() << endl;
	return 0;

}
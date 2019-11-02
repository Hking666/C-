#include<iostream>
using namespace std;
#include<deque>
namespace bit
{

	template<class T , class Con = deque<T>>
	class queue
	{
	public:
		void push(const T& data)
		{
		
			_con.push_back(data);
		}

		void pop()
		{
		
			_con.pop_front();
		}

		T& front()
		{
			return _con.front();
		}

		const T& fron()const
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		const T& back()const
		{
		
			return _con.back();
		}

		size_t size()const
		{
		
			return _con.size();
		}

		bool empty()const
		{
		
			return _con.empty();
		}


	private:
		Con _con;

	};




}

#include<list>
int  main()
{
	bit::queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	cout << q1.size() << endl;
	cout << q1.front() << endl;
	cout << q1.back() << endl;

	q1.pop();
	q1.pop();
	cout << q1.size() << endl;
	cout << q1.front() << endl;
	cout << q1.back() << endl;

	bit::queue<int, list<int>> q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;

	q2.pop();
	q2.pop();
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;
	return 0;
}
#include<iostream>
using namespace std;
#include<deque>
#include<vector>
#include <functional>
// 
namespace bit
{
	
	template<class T, class Con=vector<T> ,class Compare = less<T> >
	class priority_queue
	{
	public:
		priority_queue()
			:c()
		{

		}

		//
		template<class  Iterator>
		priority_queue(Iterator frist , Iterator last)
			: c(frist , last)
		{
			// µ÷Õû
			size_t count = c.size();
			int root = ((count - 1) >> 1);

			for (; root > 0; --root)
			{
				AdjustDown(root);
			}
		}


		void push(const T& data)
		{
			c.push_back(data);
			
			AdjustUp(c.size()-1);
		}

		void pop()
		{
			if (c.empty())
			{
				return;
			}
			swap(c[0], c[c.size() - 1]);

			c.pop_back();

			AdjustDown(0);

		}

		int size()
		{
		
			return c.size();
		}

		bool empty()
		{
			return c.empty();
		}

		const T& top()const
		{
		
			return c.front();
		}
	private:
		void AdjustDown(int parent  )
		{
			int child = (parent<<2) +1 ;

			while (child < c.size())
			{

				if (child + 1 < c.size() && com(c[child], c[child + 1]))
				{
					child += 1;
				}

				if (c[parent] > c[child])
				{
					swap(c[parent], c[child]);
				}

				parent = child;
				child = (parent << 1) + 1;

			}

			return;
		
		}


		void AdjustUp(int child)
		{
			int parent = (child - 1) >> 1;

			while ( child)
			{
				if (com(c[parent], c[child]))
				{
					swap(c[parent], c[child]);
				

				child = parent;
				parent = (child - 1) >> 1;
				}
				else
				{
					return;
				}
			}

		
		}
	private:

		Con c;
		Compare com;
	};


}

int  main()
{
	int array[] = { 8, 1, 9, 3, 6, 4, 5, 0, 2, 7 };
	bit::priority_queue<int> q(array, array + sizeof(array) / sizeof(array[0]));
	cout << q.top() << endl;

	cout << q.top() << endl;

	q.pop();
	cout << q.top() << endl;

	bit::priority_queue<int, vector<int>, greater<int>> q2;
	q2.push(5);
	q2.push(0);
	q2.push(9);
	q2.push(3);
	q2.push(14);
	return 0;
}
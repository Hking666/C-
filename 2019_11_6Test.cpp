#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<functional>

#if 0
void outMax(int sum, vector<int>& v)
{
	int count = 0;
	int s = v.size() / 3;
	
	for (int i = 0; i < s; ++i)
		sort(v.begin() + (i * 3), v.begin() + (i * 3 + 3));


	for (int i = 0; i <s; i++)
	{
		
		count += v[3 * i + 1];
	}

	cout << count << endl;
}
int main()
{

	int sum;
	int num;
	while (cin >> sum)
	{
		
		vector<int> arr;
	
		for (int i = 0; i < 3 * sum; ++i)
		{
			cin >> num;
			arr.push_back(num);

		}
		outMax(sum, arr);

		arr.resize(0);

	}
	
	
	system("pause");
	return 0;
}

#endif


#if 0
void outMax(int sum, vector<int>& v)
{
	int count = 0;
	int size = v.size();
	int s = v.size() / 3;

	sort(v.begin(), v.end());


	for (int i = size / 3; i =<(size / 3) * 2 - 1; i++)
	{

		count += v[i];
	}

	cout << count << endl;
}
int main()
{

	int sum;
	int num;
	while (cin >> sum)
	{

		vector<int> arr;

		for (int i = 0; i < 3 * sum; ++i)
		{
			cin >> num;
			if (num <1)
			{
				return 0;
			}
			arr.push_back(num);

		}
		outMax(sum, arr);

		arr.resize(0);

	}

	return 0;
}

#endif


void outMax(int sum, vector<int>& v)
{
	long long count = 0;
	int size = v.size();
	int s = v.size() / 3;

	sort(v.begin(), v.end(), greater<int>());


	for (int i = 1; s>0; i = i + 2, --s)
	{
		count += v[i];
	}

	cout << count << endl;
}
int main()
{
	vector<int> s;
	
	int sum;
	int num;
	while (cin >> sum)
	{

		vector<int> arr;

		for (int i = 0; i < 3 * sum; ++i)
		{
			cin >> num;
			arr.push_back(num);

		}
		outMax(sum, arr);

		arr.resize(0);

	}

	return 0;
}
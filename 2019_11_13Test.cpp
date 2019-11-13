#include<iostream>
using namespace std;
#include<vector>
#include<string>
#if 0
int func(int row, int col)
{
	if (row == 0 && col == 0)
	{
		return 0;
	}
	vector<vector<int>> v;
	v.resize(row);
	for (int i = 0; i<v.size(); ++i)
	{
		v[i].resize(col, -1);
	}
	int count = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j<v[i].size(); ++j)
		{
			if (-1 == v[i][j])
			{
				v[i][j] = 1;
				count++;
				if (i - 2 >= 0 && v[i - 2][j] != 1)
				{
					v[i - 2][j] = 0;
				}

				if (i + 2<v.size() && v[i + 2][j] != 1)
				{
					v[i + 2][j] = 0;
				}
				if (j - 2 >= 0 && v[i][j - 2] != 1)
				{
					v[i][j - 2] = 0;
				}

				if (j + 2<v[i].size() && v[i][j + 2] != 1)
				{
					v[i][j + 2] = 0;
				}
			}
		}

	}
	

	return count;
}

int main()
{

	int row = 0;
	int col = 0;
	while (1)
	{
		cin >> row;
		cin >> col;
		cout << func(row, col) << endl;
	}

	return 0;
}

#endif

#if 0
int main()
{

	int row = 0;
	int col = 0;
	while (1)
	{
		cin >> row;
		cin >> col;
		
		vector<vector<int>> v;
		v.resize(row);
		for (int i = 0; i<v.size(); ++i)
		{
			v[i].resize(col, -1);
		}
		int count = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			for (int j = 0; j<v[i].size(); ++j)
			{
				if (-1 == v[i][j])
				{
					v[i][j] = 1;
					count++;
					if (i - 2 >= 0 && v[i - 2][j] != 1)
					{
						v[i - 2][j] = 0;
					}

					if (i + 2<v.size() && v[i + 2][j] != 1)
					{
						v[i + 2][j] = 0;
					}
					if (j - 2 >= 0 && v[i][j - 2] != 1)
					{
						v[i][j - 2] = 0;
					}

					if (j + 2<v[i].size() && v[i][j + 2] != 1)
					{
						v[i][j + 2] = 0;
					}
				}
			}

		}


		cout<<count<<endl;
	}

	return 0;
}

#endif

int StrToInt(string str) {

	long long integ = 0;

	auto  it = str.begin();
	if (*it != '+'&& *it != '-')
	{
		return integ = 0;

	}
	int step = -1;
	if (*it <= '9' || *it >= '0')
	{
		step = *it - '0';

	}
	char flag = *it;
	it++;
	while (it<str.end())
	{
		if (*it>'9' || *it<'0')
		{
			integ = 0;
			break;
		}
		if (flag == '+' || step >= 0)
			integ = integ * 10 + (*it - '0');

		if (flag == '-')
			integ = -(*it - '0') + integ * 10;

		++it;

	}

	return integ;

}

int main()
{

	string s;
	while (getline(cin,s))
	{
		
		cout << StrToInt(s) << endl;
		s.clear();
	}

	return 0;
}
#include <iostream>
#include <iostream>
using namespace std;
#include <vector>
int Func(int n)
{
	vector<vector<int>> vv;
	vv.resize(n);

	for (int i = 0; i< n; ++i)
	{
		vv[i].resize(2 * n, 0);
		vv[i][1] = 1;
	}
	for (int i = 1; i< n; ++i)
	{
		for (int j = 2; j<2 * (i + 1); ++j)
		{
			vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
		}
	}

	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i<vv[n - 1].size(); ++i)
	{
		if (0 == vv[n - 1][i] % 2)
			return i;
	}

	return -1;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << Func(n) << endl;

	}
}
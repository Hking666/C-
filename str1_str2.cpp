#include<iostream>
using namespace std;
#include<string>
#include<assert.h>
void Delsame(string& s1, string& s2)
{

	string outstr;
	
	if (s1.empty() && s2.empty())
	{
		return;
	}

	for (int i = 0; i<s1.size(); ++i)
	{
		int flag = 1;
		for (int j = 0; j<s2.size(); ++j)
		{
			if (s1[i] == s2[j] && s1[i] != ' ')
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
		{
			outstr.push_back(s1[i]);
		}
	}

	cout << outstr << endl;;
}
int main()
{
	string s1;
	string s2;

	while (getline(cin, s1))
	{
		getline(cin, s2);
		Delsame(s1, s2);
	}



	return 0;
}
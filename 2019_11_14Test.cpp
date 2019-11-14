#include<iostream>
using namespace std;
#include<stack>
#include<string>
bool chkParenthesis(string A, int n) {
	// write code here
	stack<char> s;
	auto it = A.begin();
	while (it != A.end())
	{
		if (*it == '(' || *it == ')')
		{
			if (*it == '(')
				s.push(*it);
			else
				s.pop();
		}
		else
		{
			return false;
		}
		++it;

	}

	if (s.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string A("()()()");
	cout<<chkParenthesis(A, 6)<<endl;
	system("pause");
	return 0;
}
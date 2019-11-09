#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int MoreThanHalfNum_Solution(vector<int> numbers) {
	int size = numbers.size();
	vector<int> v(numbers);
	sort(v.begin(), v.end());
	int count = 0;
	int judg = -1;
	for (int i = 0; i < size; ++i)
	{
		if (v[i] != judg)
		{
			judg = v[i];
			count = 0;
		}
		if (v[i] == judg)
		{
			count++;
		}
		
		if (count > size / 2)
		{
			return v[i];
		}

	}
	
		return 0;
	
}

int main()
{
	vector<int> arr{1,2,3,2,2,2,5,4,2};
 	cout<<MoreThanHalfNum_Solution(arr);
	system("pause");
	return 0;
}
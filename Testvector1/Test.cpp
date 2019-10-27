#include<iostream>
using namespace std;
#include<vector>
int DupArray(vector<int>& nums){
	int size = nums.size();
	for (auto& e: nums){
		if (e<0 || e>size - 1)
		{
			return -1;
		}
	}
	for (int i = 0; i < size; ++i){	
		
		if (i == nums[i]){

			continue;
		}

		while (i != nums[i] && nums[nums[i]] != nums[i]){
		
			swap(nums[i], nums[nums[i]]);
		}
	
		if (i != nums[i] && nums[nums[i]] == nums[i])
		{
			return nums[i];
		}
		
	}
	return -1;
}
int  main()
{

	vector<int> arr{ 0, 3, 3, 2,3 };
	cout << DupArray(arr) << endl;
	system("pause");
	return 0;
}
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int numSzie = nums.size();
        if(numSzie == 0)
        {
            return 0;
        }
        int j =0;
        for(int i = 0; i < numSzie;i++)
        {
            if(val != nums[i])
            {
                nums[j] = nums[i];
                j++;
            }
            
        } 
        return j;
    }
};

class Solution {
public:
  
    int findKthLargest(vector<int>& nums, int k) {
        
     
    priority_queue<int> q(nums.begin(), nums.end()); // 区间构造将nums的数存入优先队列，默认less，按照大堆
    
    while(--k) // 出前k-1个top，
    {
        q.pop();
    }
    return q.top(); // 此时，top元素就是第k个最大的元素。
    }
};




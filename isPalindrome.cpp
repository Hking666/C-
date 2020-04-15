class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
        return false;

        int y = x;
        long long val = 0;
        while(y)
        {
            val = val*10 + y%10;
            y = y/10;

        }
        if(x == val)
            return true;
        else
            return false;
    }
};

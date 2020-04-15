class Solution {
public:
    bool isPalindrome(int x) {
        string tmp=to_string(x);
        string tmp2=tmp;
        reverse(tmp2.begin(),tmp2.end());
        if(tmp==tmp2) return true;
        return false;
        // for(int i=tmp.size()-1,j=0;i>0,j<i;i--,j++)
        //     if(tmp[i]!=tmp[j]) return false;
        // return true;
    }
};

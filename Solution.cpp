class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        if(pushV.size() != popV.size())
        {
            return false;
        }
        stack<int> s;
        int inIdex = 0;
        int outIdex = 0;
        while(outIdex < popV.size())
        {
            while(s.empty()|| s.top() != popV[outIdex] )
            {
                if( inIdex < pushV.size()) 
                {
                    s.push(pushV[inIdex]);
                    ++inIdex;
                }
                else
                return false;
            }
            
            s.pop();
            ++outIdex;
        }
        return true;
    }
};

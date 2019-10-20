
class Solution {
public:
    string addStrings(string num1, string num2) {
        int Lsize = num1.size();
        int Rsize = num2.size();
        if(Lsize < Rsize)
        {
            num1.swap(num2);
            swap(Lsize,Rsize);
        }
        
        string strRet(Lsize+1,'0');
    
        char offset = 0;
       
        for(int LIdx = num1.size()-1 , RIdx = num2.size()-1; LIdx>=0;LIdx-- ,RIdx--)
        {
            char cRet = num1[LIdx] - '0';
            if(RIdx >= 0)
            {
                
                cRet += num2[RIdx] - '0';
            }
            
             cRet += offset;
            offset = 0;
            if(cRet >= 10)
            {
                
                offset = 1;
                cRet -=10;
            }
            
            strRet[LIdx+1] += cRet;
            
        }
        if(offset == 1)
            strRet[0] += 1;
        else
            strRet.erase(strRet.begin());
        return strRet;
    }
};

int main()
{
  
  return 0;
}

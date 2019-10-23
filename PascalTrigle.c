class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> vv; // 定义二维数组
        vv.resize(numRows); //一共numRows行 
        for(int i = 0 ; i < numRows ; i++ )
        {
            vv[i].resize(i+1,0); //每行 i+1列
            vv[i][0] = 1; // 第一列为1
            
            vv[i][i] = 1; // i行i列为1
            
        }
        
        for(int i = 0 ; i < vv.size() ; i++ )
        {
            for(int  j = 1 ; j < i ; j++)
            {
                
                vv[i][j] = vv[i-1][j-1] + vv[i-1][j];                
            }
            
            
        }
        
        return vv;
    }
};

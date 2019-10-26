class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0 ; i <tokens.size() ; i++){
            
            string& str = tokens[i];
            if (!("+" == str || "-" == str || "*" == str || "/" == str)){
                  // 数字压栈
                 s.push(atoi(str.c_str() ));
             }
             else{ 
                      //逆波兰表达式 操作符后置，数字顺序不变
                 int  right= s.top(); //第二个操作数 
                 s.pop();
                 
                 int left = s.top(); // 第一个操作数
                 s.pop();
                 
                 switch(str[0])
                 {
                     case '+':
                         s.push(left+right);
                         break;
                     case '-':
                         s.push(left-right);
                         break;
                     case '*':
                         s.push(left*right);
                         break;
                     case '/':
                         s.push(left/right); // 题目特殊申明，第二个操作数不为0
                         break;
                                  
                 }
             }
                 
        }
                  
                  return s.top();
    }
};


class MinStack {
public:
       MinStack() {
        
    }
    
    void push(int x) {
        
        data.push(x);
        if(minstack.empty() || x <= minstack.top())// 当最小栈为空时或压栈元素小于等于栈顶元素，最小栈入栈

        {
            
            minstack.push(x);
        }
    }
    
    void pop() {
        
        if(data.top() == minstack.top()) // 当数据栈顶元素 == 最小栈顶元素时，最小栈出栈
        {
            minstack.pop();
        }
        
        data.pop();
    }
    
    int top() {
        
        return data.top();
    }
    
    int getMin() {
        
        return minstack.top();
    }
    
private:
	//创建两个栈
    stack<int> data; 
    stack<int> minstack;
    
};

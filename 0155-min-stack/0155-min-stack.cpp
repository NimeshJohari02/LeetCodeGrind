class MinStack {
public:
        stack<int>mainStack;
        stack<int>secondStack;
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        if(secondStack.empty()){
            secondStack.push(val);
        }
        else{
            int currMin = secondStack.top();
            if(val<=currMin)secondStack.push(val);
        }
    }
    
    void pop() {
        int top = mainStack.top();
        mainStack.pop();
        if(!secondStack.empty() && secondStack.top()==top)secondStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    int getMin() {
         if(secondStack.empty()) return 0 ;
        return secondStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
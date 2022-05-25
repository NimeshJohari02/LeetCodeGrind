class MyQueue {
public:
    stack<int> input , output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int ans = output.top();
            output.pop();
            return ans;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int ans = output.top();
            output.pop();
            return ans;
        }
    return -1;
    }
    
    int peek() {
         if(!output.empty()){
            int ans = output.top();
            return ans;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int ans = output.top();
            return ans;
        }
     return -1;   
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
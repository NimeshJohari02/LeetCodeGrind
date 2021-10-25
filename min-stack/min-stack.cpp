class MinStack {
public:
    /** initialize your data structure here. */
      stack<int> main;
    stack<int>helper;
    MinStack() {
    }
    void push(int val) {
        if(helper.empty()){
          main.push(val);
          helper.push(val);
          return ;
        }
      if(val<=helper.top()){
        helper.push(val);
        main.push(val);
        return;
      }
      main.push(val);
      return;
    }
    
    void pop() {
      if(main.empty()){
        return;
      }
      if(main.top()==helper.top()){
        main.pop();
        helper.pop();
        return;
      }
      main.pop();
      return ;
    }
    
    int top() {
        if(!main.empty())
        return main.top();
      return -1;
    }
    
    int getMin() {
    if(!helper.empty())
     return helper.top() ;  
    return 0;
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
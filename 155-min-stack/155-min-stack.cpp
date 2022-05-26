// class MinStack {
// public:
//     stack<int> mainStack ;
//     stack<int> helper;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         mainStack.push(val);
//         if(helper.empty() || helper.top() > val) helper.push(val);
//     }
//     void pop() {
//      int val = mainStack.top();
//         mainStack.pop();
//         if(!helper.empty() && helper.top() == val) helper.pop();
//         return ;
//     }
    
//     int top() {
//         return mainStack.top();
//     }
    
//     int getMin() {
//         return helper.top();
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */


class MinStack {
public:
    stack<long long int> stk ;
    long long mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value;
        if(stk.empty() ){
            mini = val;
            stk.push(val);
        }
        else{
            if(mini > val){
                stk.push((2 * val * 1LL) - mini);
                mini = val;
            }
            else stk.push(val);
        }
    }
    void pop() {
     if(stk.empty()) return ;
        long long el = stk.top();
        stk.pop();
        if(el > mini )return ;
        else {
            mini = 2 * mini - el;
        }
    }
    
    int top() {
        long long el = stk.top();
        if(el > mini) return el;
        else return mini;
    }
    
    int getMin() {
        return mini;
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


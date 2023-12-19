class Solution {
public:
    int evaluate(int op2 , int op1, char ch ){
        switch(ch){
            case '+': return op2+op1; break;
            case '-': return op2-op1; break;
            case '*': return op2*op1; break;
            case '/': return op2/op1; break;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;
        for(string it : tokens){
            char ch = it[0];
            if(it.size()>1 || isdigit(ch))
                stk.push(stoi(it));
            else{
                int operand1 = stk.top();
                stk.pop();
                int operand2 = stk.top();
                stk.pop();
                int ans = evaluate(operand2 , operand1 , ch);
                stk.push(ans);
            }
        }
        return stk.top();
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;
        for(auto str : tokens ){
            char ch = str[0];
            if(str.size()>1 ||isdigit(ch)){
                //! NOTE here pushing
                // cout<<stoi(str)<<"  -> "<<ch-'0'<<endl;  // As result could be multidigit not use to use this ; 
                stk.push(stoi(str));
            }
            else{
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                int res = 0;
                switch(ch){
                    case '+':
                        res=op1+op2;
                        break;
                    case '*':
                        res=op1*op2;
                        break;
                    case '-':
                        res=op1-op2;
                        break;
                    case '/':
                        res=op1/op2;
                        break;
                }
                stk.push(res);
            }
        }
        
        return stk.top();
    }

};
class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        
        stack<int>stk;
        for(string& it:ops)
        {
            if(it == "C")
            {
                stk.pop();
            }
            else if(it == "D")
            {
                stk.push(stk.top()*2);
            }
            else if(it == "+")
            {
                int o1 = stk.top();
                stk.pop();
                int o2 = stk.top();
                stk.push(o1);
                stk.push(o1+o2);
            }
            else
            {
                stk.push(stoi(it));
            }
        }
        int res =0 ; 
        while(stk.size() != 0)
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
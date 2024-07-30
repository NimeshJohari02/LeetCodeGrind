class Solution {
public:
    string removeKdigits(string num, int k) {
        // Greedy would work fine here .
        // Edge Cases 
        // k ==n .  Truncation of 0's . num = 123456 k = 3 (Remove last)
        stack<int>stk;
        for(int i=0 ; i < num.size() ; i++){
            int currentNumber = num[i]-'0';
            while(!stk.empty() && k>0 && stk.top() >currentNumber){stk.pop();k--;}
            stk.push(currentNumber);
        }
        while(k--)stk.pop();
        if(stk.empty())return "0";
        string ans = "";
       while(!stk.empty()){
            ans += to_string(stk.top());
           stk.pop();
       }
        // remove ending 0 
        while(!ans.empty() && ans.back()=='0')ans.pop_back();
        if(ans.empty())return "0";
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};
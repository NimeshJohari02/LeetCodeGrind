class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans  =0;
        stack<char> stk;
        for(int i = s.length()-1 ; i >=0 ; i--){
            if(s[i]=='('){
                if(stk.empty()){
                    ans++;
                }
                else{
                    stk.pop();
                }
            }
            else{
                stk.push(')');
            }
        }
        return ans + stk.size();
    }
};
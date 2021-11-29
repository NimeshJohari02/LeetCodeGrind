class Solution {
public:
    int minAddToMakeValid(string s) {
              stack<char>stk;
        int cnt=0;
        for(int i = s.length()-1 ; i>=0 ; i--){
            if(s[i]==')')
                stk.push(')');
            if(s[i]=='('){
                if(!stk.empty()){
                stk.pop();
                }else{
                    cnt++;
                }
            }
        }
        
        return cnt+stk.size();  
    }
};
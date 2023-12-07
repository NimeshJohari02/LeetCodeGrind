class Solution {
public:
    string removeStars(string s) {
      stack<char>stk;
        string ans="";
        for(auto&it : s){
            if(it!='*')stk.push(it);
            else {
                stk.pop();
            }
        }
        while(!stk.empty())
            ans+=stk.top() , stk.pop();
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};
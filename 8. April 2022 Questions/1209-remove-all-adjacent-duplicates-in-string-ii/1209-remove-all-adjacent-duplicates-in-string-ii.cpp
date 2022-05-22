class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char , int>> stk;
        for(int i=0 ; i < s.size() ; i++){
        int temp = k;
            if(!stk.empty() &&  s[i] == stk.top().first){
                stk.push({stk.top().first , stk.top().second +1});
            }
            else{
                stk.push({s[i] , 1});
            }
            
            if(!stk.empty() && stk.top().second == temp){
                while(temp--)stk.pop();
            }
        }
        string ans = "";
        while(!stk.empty()) {
            // string temp = string(stk.top().second  ,  stk.top().first );
            ans+=stk.top().first;
            stk.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
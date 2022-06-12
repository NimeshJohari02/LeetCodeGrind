class Solution {
public:
    int rec(int idx , string &s){
        int n = s.size();
        if(idx == n) return 1;
        // Starting With 0 is not allowed
        if(s[idx] == '0') return 0;
        int ans = rec(idx+1 , s);
        if(idx < n-1  && (s[idx] =='1' || s[idx]=='2' && s[idx+1]<='6'))
            ans += rec(idx+2 , s);
        return ans;
    }
    int mem(int idx , string &s , vector<int>&dp){
         int n = s.size();
        if(idx == n) return 1;
        // Starting With 0 is not allowed
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = mem(idx+1 , s, dp);
        if(idx < n-1  && (s[idx] =='1' || s[idx]=='2' && s[idx+1]<='6'))
            ans += mem(idx+2 , s, dp);
        return dp[idx] = ans;
    }
    int topDown(string s){
        int n = s.size();
        vector<int>dp(n+1 , 0);
        dp[n] = 1;
        for(int idx = n-1 ; idx >=0 ; idx--){
        if(s[idx]=='0'){
                dp[idx] =0 ;
                continue;
            }
        dp[idx] += dp[idx+1];
        if(idx < n-1  && (s[idx] =='1' || s[idx]=='2' && s[idx+1]<='6'))
            dp[idx] += dp[idx+2];   
        }
        return dp[0];
    }
    int numDecodings(string s) {
        // return rec(0 , s);
        // vector<int>dp(s.size() , -1);
        // return mem(0 , s , dp);
        return topDown(s);
    }
};
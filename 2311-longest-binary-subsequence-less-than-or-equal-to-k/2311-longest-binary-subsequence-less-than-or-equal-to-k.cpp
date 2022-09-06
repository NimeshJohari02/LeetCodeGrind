class Solution {
public:
    
    int rec(int idx , string &str , int target , int base ,  vector<vector<int>>&dp){
        if(idx < 0 ){
            return 0 ;
        }
        if(dp[idx][base]!= -1) return dp[idx][base];
        int pick =  0 , notPick = 0 ;
        notPick = rec(idx-1 , str , target, base , dp);
        if((target - (str[idx]-'0')*pow(2 , base))>=0 )
            pick = 1 + rec(idx-1 , str , target - (str[idx]-'0')*pow(2 , base)  , base+1 , dp);
        return dp[idx][base] = max(pick , notPick);
    }
    int longestSubsequence(string s, int k) {
        int n = s.size() ;
        vector<vector<int >>dp(n  ,vector<int>(n , -1) );
        return rec(n-1 , s , k ,0 , dp);
    }
};
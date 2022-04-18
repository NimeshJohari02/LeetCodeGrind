class Solution {
public:
    int helper(int idx1 , int idx2 , string& s1 , string &s2 , vector<vector<int>>&dp){
        if(idx2<0) return 1 ;
        if(idx1<0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]= helper(idx1-1 , idx2-1 , s1 , s2 , dp) + helper(idx1-1 , idx2 , s1 , s2 , dp);
        }
        return dp[idx1][idx2] = helper(idx1-1 , idx2 , s1 , s2 , dp);
    }
    int numDistinct(string s, string t) {
        int m = s.size() , n = t.size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return helper(m-1 ,n-1 , s , t , dp);
    }
};
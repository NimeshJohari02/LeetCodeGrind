class Solution {
public:
    int helper(int idx1 , int idx2 , string&s , string &t , vector<vector<int>>&dp){
        if(idx1<0) return idx2+1;
        if(idx2<0) return idx1+1;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == t[idx2]){
            return dp[idx1][idx2] = helper(idx1-1 , idx2-1 , s , t , dp);
        }
            int insert = helper(idx1 , idx2-1 , s , t , dp);
            int deleteElement =helper(idx1-1 , idx2 , s , t , dp);
            int replace =  helper(idx1 -1 , idx2 -1 , s, t, dp);
            return dp[idx1][idx2] =1 +  min(min(insert , deleteElement) , replace);
    }
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size() ;
        vector<vector<int>>dp(m , vector<int>(n , -1));
        return helper(m-1 , n-1 , word1 , word2 , dp);
    }
};
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
    int tabulation(string &s1 , string &s2){
        long long int m = s1.size() , n = s2.size();
        vector<vector<double>> dp(m+1, vector<double>(n+1 , 0));
        for(int i=0 ; i <= m ; i++)
            dp[i][0] =1 ;
        for(int i=1 ; i <= m ; i++){
            for(int j=1 ; j <= n ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j]  = dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[m][n];
    }
    int numDistinct(string s, string t) {
        int m = s.size() , n = t.size();
        // vector<vector<int>> dp(m , vector<int>(n , -1));
        // return helper(m-1 ,n-1 , s , t , dp);
        return tabulation(s , t);
    }
};
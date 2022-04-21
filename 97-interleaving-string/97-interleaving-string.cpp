class Solution {
public:

    bool helper(int i , int j , int k , string &s1 , string &s2 , string &s3 , vector<vector<vector<int>>>&dp){
        if(i==s1.size() and j == s2.size()  and k ==s3.size()) return true;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(s1[i] == s3[k] && s2[j] == s3[k])
            return dp[i][j][k] = (helper(i+1 , j , k+1 , s1 ,s2 ,s3 , dp) | helper(i , j+1 , k+1 , s1 , s2 , s3 , dp));
        else if(s1[i] == s3[k])
            return dp[i][j][k]= helper(i+1 , j , k+1 , s1 ,s2 ,s3 , dp) ;
        else if(s2[j] == s3[k])
            return  dp[i][j][k]= helper(i , j+1 , k+1 , s1 , s2 , s3 , dp);
        return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<vector<int>>>dp(s1.size() +1 ,vector<vector<int>> (s2.size()+1 , vector<int>(s3.size() +1, -1)));
        return helper(0 , 0  , 0 , s1 , s2 , s3 , dp);
    }
};
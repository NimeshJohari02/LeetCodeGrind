class Solution {
public:

    /**
    We can use 2 parameters rather than 3 and use the relation that i + j == k alwaysss 
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
    */
    
    bool rec(int i , int j , string &s1 , string &s2, string &s3){
        if(i==s1.size() && j == s2.size()) return true;
        bool ans = false;
        if(i < s1.size() && s1[i] == s3[i+j])
            ans |= rec(i+1 , j , s1 , s2 ,s3);
        if(j < s2.size() && s2[j] == s3[i+j])
            ans |= rec(i, j+1 , s1 , s2 ,s3);
        return ans;
    }
    
    bool memo(int i , int j , string &s1 , string &s2 , string &s3 , vector<vector<int>>&dp){
        if(i==s1.size() && j ==s2.size()) return dp[i][j]=true;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(i < s1.size() && s1[i] == s3[i+j]) ans |= memo(i+1 , j , s1 , s2 ,s3 , dp);
        if(j < s2.size() && s2[j] == s3[i+j]) ans |= memo(i , j+1 , s1 ,s2 ,s3 ,dp);
        return dp[i][j] = ans;
     }
    bool tabulation(string &s1 , string &s2 , string &s3){
        int m = s1.size() , n = s2.size();
        vector<vector<bool>> dp(m+1 , vector<bool>(n+1 , false));
        dp[m][n] = true;
        for(int i= m ; i >=0  ; i--){
            for(int j = n ; j>=0 ; j--){
                if(i < s1.size() && s1[i] == s3[i+j]) dp[i][j] = dp[i][j] | dp[i+1][j];
                if(j < s2.size() && s2[j] == s3[i+j]) dp[i][j] =dp[i][j] | dp[i][j+1];
                }
        }
        return dp[0][0];
    }
    bool isInterleave(string s1, string s2, string s3) {
         if(s1.size() + s2.size() != s3.size()) return false;
        // vector<vector<vector<int>>>dp(s1.size() +1 ,vector<vector<int>> (s2.size()+1 , vector<int>(s3.size() +1, -1)));
        // return helper(0 , 0  , 0 , s1 , s2 , s3 , dp);
        // return rec(0 , 0 , s1 , s2, s3);
        // vector<vector<int>>dp(s1.size()+1 , vector<int>(s2.size() +1 , -1));
        // return memo(0 , 0 , s1 , s2 , s3 , dp);
        return tabulation(s1 , s2 , s3);
        
    }
};
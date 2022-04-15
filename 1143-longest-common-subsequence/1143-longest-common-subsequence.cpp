class Solution {
public:
    int rec(int idx1 , int idx2 , string s1 , string s2){
        if(idx1==-1 || idx2==-1 )return 0;
        if(s1[idx1]== s2[idx2]) return 1 + rec(idx1-1 , idx2-1 , s1 , s2);
        return max(rec(idx1-1 , idx2 , s1 , s2) , rec(idx1 , idx2-1 , s1 , s2));
    }
    int memoized(int idx1 , int idx2 , string &s1 , string &s2 , vector<vector<int>>&memo){
        if(idx1==-1 || idx2==-1 )return 0;
        if(memo[idx1][idx2] != -1) return memo[idx1][idx2];
        if(s1[idx1]== s2[idx2]) return memo[idx1][idx2] = 1 + memoized(idx1-1 , idx2-1 , s1 , s2, memo);
        return memo[idx1][idx2]= max(memoized(idx1-1 , idx2 , s1 , s2 , memo) , memoized(idx1 , idx2-1 , s1 , s2 , memo));
    }
    int tabulation(string &s1 , string &s2){
        int m = s1.size()  , n = s2.size() ;
        vector<vector<int>> dp(m+1 , vector<int>( n+1 , 0));
        for(int i=1 ; i <= m ; i++)
            for(int j=1 ; j <=n ; j++)
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        return dp[m][n];
    }
    int spaceOptimized(string &s1 , string &s2){
        int m=s1.size() , n = s2.size() ;
        vector<int>prev(n +1, 0) , curr(n +1, 0);
         for(int i=1 ; i <= m ; i++){
            for(int j=1 ; j <=n ; j++){
                if(s1[i-1] == s2[j-1])
                   curr[j] = 1+prev[j-1];
                else 
                    curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
         }
        return prev[n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return rec(text1.size()-1 , text2.size()-1 , text1 , text2);
        // int n = text1.size() , m = text2.size();
        // vector<vector<int>> memo(n , vector<int>(m  ,-1));
         // return memoized(n-1 , m-1 , text1 , text2 , memo);
        // return tabulation(text1 , text2);
        return spaceOptimized(text1 , text2);
    }
    
};
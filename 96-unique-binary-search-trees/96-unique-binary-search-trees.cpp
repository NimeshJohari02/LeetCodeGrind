class Solution {
public:
    // Recursion 
    int rec(int n){
        if(n <0) return 0 ;
        if(n==0 || n==1) return 1;
        int res = 0 ;
        for(int i=1 ; i <= n ; i++)
            res += rec(i-1) * rec(n-i);
        return res;
    }
    // Memo
    int mem(int n , vector<int>&dp){
        if(n==0 || n==1) return dp[n] = 1;
        if(dp[n] != -1) return dp[n];
        int ans =0;
        for(int i=1 ; i <= n ; i++)
            ans += mem(i-1 , dp) * mem(n-i , dp);
        return dp[n] = ans;
    }
    // Tabulation 
    int tab(int n){
        vector<int>dp(n+2 , 0);
        dp[0]=1 , dp[1] = 1;
        for(int i =2 ; i <= n ; i++){
            int ans =0 ;
            for(int j = 1 ; j<=i ; j++)
             ans += dp[j-1]* dp[i-j]; 
            dp[i] = ans;
        }
    return dp[n];
    }
    //Most Optimized Cataln Number
    long long ncr(int n , int r){
        // keep multiplying by n-i and dividing by i+1;
        long long ans = 1 ;
        for(int i=0 ; i< r ; i++){
            ans *= n-i;
            ans /= i+1;
        }
        return ans;
    }
    int catalan(int n ){
        // Catalan Number = 1/(n+1) * (2nCn);
        return ncr(2*n , n)/(n+1);
    }
    
    int numTrees(int n) {
         // return rec(n);   
        // vector<int>dp(n+1 , -1);
        // return mem(n , dp);
        // return tab(n);
        return catalan(n);
    }
};
class Solution {
public:
    long long int MOD = (long long int)1e9+7;
    long long int memo(int n , vector<long long int > &dp){
        if(n==1) return dp[n] =  2 ;
        if(n==2) return dp[n] = 3 ;
        if(dp[n] != -1) return dp[n];
        long long int pick = 1e9+7 , npick = 1e9+7;
         pick = memo(n-2 , dp) % MOD;
         npick = memo(n-1 , dp) % MOD;
        return dp[n]= (pick + npick) % MOD;
    }
    int countHousePlacements(int n) {
        vector<long long int >dp(n +1, -1);
        memo(n , dp);
        long long ans =(dp[n]  * dp[n]) % MOD;
        return ans % MOD;
    }
};
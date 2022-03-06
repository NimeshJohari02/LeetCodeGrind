class Solution {
public:
    const int MOD = 1e9+7;
    int countOrders(int n) {
        // rec = ans(n-1) * 2*n c2 
        vector<long long int>dp(n+1 , 0);
        if(n==1)return 1;
        dp[1]=1;
        dp[2]=6;
        for(int i=3 ; i <= n ; i++){
            dp[i] = (dp[i-1] % MOD * ((2*i) *  (2*i-1)) / 2 ) % (int) MOD;
        }
        return dp[n] % MOD ;
    }
};
class Solution {
public:
    int numTilings(int n) {
        vector<long long int> dp(1001, 0);
        
        dp[0]=1;
        dp[1]=2;
        dp[2]=5;
        int mod = 7+1e9;
        for(int i=3 ; i<=n;i++){
            dp[i]= (2*dp[i-1]%mod+dp[i-3]%mod)%mod; 
        }
        return dp[n-1];
    }
};
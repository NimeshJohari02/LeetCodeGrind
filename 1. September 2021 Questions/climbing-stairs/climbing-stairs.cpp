class Solution {
public:
    int climbStairs(int n) {
            long long int dp[50];
            dp[0]=0;
            dp[1]=1;
            dp[2]=2;
            for(int i=3;i<50;i++){
                    dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];

    }
};
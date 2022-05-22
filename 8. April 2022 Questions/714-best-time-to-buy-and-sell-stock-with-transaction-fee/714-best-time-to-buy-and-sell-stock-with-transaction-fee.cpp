class Solution {
public:
      int tabulation(vector<int>&prices , int fee){
        int n =prices.size() ;
        vector<vector<int>>dp(n+2 , vector<int>(2 , 0));
        for(int i= n-1 ; i >=0 ;i--){
            // for(int b=0 ; b<=1 ; b++)
                // if(b)
                    dp[i][1] = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
                // else
                    dp[i][0] = max(prices[i] + dp[i+1][1] -fee, dp[i+1][0]);
        }
    return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return tabulation(prices , fee);
    }
};
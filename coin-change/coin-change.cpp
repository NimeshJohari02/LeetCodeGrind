class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1 ,amount+1);
        // For making an amount as 0 you need 0 coins thus the initialization condition for such cases changes 
        dp[0]=0;
        for(int i = 1 ; i <= amount ; i++){
            for(int j = 0 ; j < coins.size() ; j++){
                if(i >= coins[j] ){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        cout<<dp[amount]<<endl;
        return dp[amount]== amount+1 ? -1 : dp[amount];
    }
};
/*
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int buyIdx =0;
        //  The idea is to buy at local min and dont sell till next element is larger than currPrice . This way 
           /s\      /s\    /(s)
          /   \    /   \  /
        b/     \b /     \b
        even if you have something like this  you can buy and sell plus add the last case . ie after the end of the loop 
        add 
         currProfit+=(prices[sellIdx]-prices[buyIdx]);
        because just in case there is no dip at the last just like above given figure then that part will not be included 
        if there is a dip then the val would be zero hence no over counts .
        
        int sellIdx =0;
        int currProfit =0;
        for(int i =1 ; i < prices.size() ; i++){
            if(prices[i]>=prices[i-1]){
                sellIdx++;
            }
            else{
                currProfit+=(prices[sellIdx]-prices[buyIdx]);
                sellIdx=buyIdx=i;
            }
        }
         currProfit+=(prices[sellIdx]-prices[buyIdx]);
        return currProfit;
    }
};

*/
class Solution {
public:
    int rec(int idx , bool canBuy  , vector<int>&prices){
        int profit = 0;
        if(idx==prices.size()) return 0;
        if(canBuy){
            profit = max(-prices[idx]+rec(idx+1 , !canBuy , prices ) , rec(idx+1 , canBuy , prices));
        }
        else{
            profit = max(prices[idx] + rec(idx+1 , true , prices) , rec(idx+1 , canBuy , prices));
        }
        return profit;
    }
    int mem(int i , bool buy , vector<int>&prices , vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        int profit = 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            profit = max(-prices[i]+mem(i+1 , !buy , prices,dp ) , mem(i+1 , buy , prices ,dp));
        }
        else{
            profit = max(prices[i] + mem(i+1 , true , prices , dp) , mem(i+1 , buy , prices, dp));
        }
        return dp[i][buy] = profit ;   
    }
    
    int tabulation(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));
        // dp[n][0] = 0 , ; dp[n][1] = 1 // base case already 0;
        for(int i = n-1 ; i >=0 ; i--){
            for(int buy =0 ; buy <=1 ; buy++){
        int profit =0 ;
        if(buy){
            profit = max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
        }
        else{
            profit = max(prices[i] + dp[i+1][1] , dp[i+1][0]);
        }
            dp[i][buy]  = profit;
            }
        }
        return  dp[0][1];
    }
    
    
    int space(vector<int>&prices){
        int n = prices.size();
        // vector<vector<int>>dp(n+1 , vector<int>(2 , 0));
        // dp[n][0] = 0 , ; dp[n][1] = 1 // base case already 0;
        vector<int>ahead(2, 0) , curr(2, 0);
        
        for(int i = n-1 ; i >=0 ; i--){
            for(int buy =0 ; buy <=1 ; buy++){
        int profit =0 ;
        if(buy){
            profit = max(-prices[i]+ahead[0] , ahead[1]);
        }
        else{
            profit = max(prices[i] + ahead[1] , ahead[0]);
            }
            curr[buy]  = profit;
            }
            ahead = curr;
        }
        return  ahead[1];
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        // return rec(0 ,true , prices );
        // vector<vector<int>>dp(prices.size() , vector<int>(2 , -1));
        // return  mem(0 , 1 , prices , dp);
        // return tabulation(prices);
        return space(prices);
    }
};
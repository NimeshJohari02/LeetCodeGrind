class Solution {
public:
    int mem(int i , int buy , int c ,vector<int>&price ,  vector<vector<vector<int>>>&dp){
        if(c ==0) return 0;
        if(i== price.size()) return 0;
        if(dp[i][buy][c] != -1) return dp[i][buy][c];
        if(buy){
            return dp[i][buy][c] = max(-price[i] + mem(i+1 , 0 , c , price , dp) , mem(i+1 , 1 ,c , price , dp));
        }
        else{
            return dp[i][buy][c] = max(price[i] + mem(i+1 , 1 , c-1 , price , dp) , mem(i+1, 0 , c , price , dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
     vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));   
        return mem(0 , 1 , 2 , prices , dp);
    }
};
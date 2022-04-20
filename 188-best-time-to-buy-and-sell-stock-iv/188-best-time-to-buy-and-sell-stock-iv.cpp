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
    int tabulation(vector<int>&prices , int k ){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2 , vector<int>(k+1 , 0)));   
        // for(int i=0 ; i < n ; i++)
        //     for(int b =0 ;b <=1 ;b++)
        //         dp[i][b][0] =0;
        // for(int b=0;b<=1;b++)
        //     for(int c=0;c<=2;c++)
        //         dp[n-1][b][c] =0;
        for(int i = n-1 ; i>=0 ; i--){
            for(int b=0 ; b <=1 ; b++){
                for(int c =1 ; c<=k; c++){
                    if(b){
                        dp[i][b][c] = max(-prices[i] + dp[i+1][0][c], dp[i+1][1][c]);
                    }
                    else{
                        dp[i][b][c] = max(prices[i]+dp[i+1][1][c-1] , dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size() , vector<vector<int>>(2 , vector<int>(k+1 , -1)));   
        // return mem(0 , 1 , k+1 , prices , dp);
        return tabulation(prices , k);
    }
};
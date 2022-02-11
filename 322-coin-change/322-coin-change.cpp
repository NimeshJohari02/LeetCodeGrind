class Solution {
public:
    int rec(int idx , vector<int>&arr , int target){
        if(idx==0){
            if(target%arr[idx]==0)
                return target/arr[idx];
            return 1e9;
        }
        int notTake = rec(idx-1 , arr , target);
        int take = 1e9;
        if(arr[idx]<= target)
            take = rec(idx , arr , target - arr[idx]) + 1;
    return min(take , notTake);
    }
    int memo(int idx , vector<int>&arr , int target , vector<vector<int>>&dp){
        if(idx==0){
            if(target%arr[idx]==0)
                return dp[idx][target]=target/arr[idx];
            return 1e9;
        }
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        int notTake = memo(idx-1 , arr , target , dp);
        int take = 1e9;
        if(arr[idx]<= target)
            take = memo(idx , arr , target - arr[idx] , dp) + 1;
    return dp[idx][target]=min(take , notTake);
    }
    int tabulation(vector<int>&arr , int target){
        vector<vector<int>>dp(arr.size() , vector<int>(target+1 , 0));
        int n = arr.size();
        for(int t =0 ; t<=target;t++){
            dp[0][t] = t%arr[0]==0?t/arr[0]:1e9;
        }
        for(int i=1; i< n; i++){
            for(int t=1; t<=target ; t++){
                int notTake = dp[i-1][t];
                 int take = 1e9;
                 if(arr[i]<= t)
                      take = dp[i][t-arr[i]] + 1;
            dp[i][t] = min(take , notTake);
            }
        }
        return dp[n-1][target];
    }
    int spaceOptimization(vector<int>&arr , int target){
        // vector<vector<int>>dp(arr.size() , vector<int>(target+1 , 0));
        vector<int>prev(target+1, 0) , curr(target+1,0);
        int n = arr.size();
        for(int t =0 ; t<=target;t++){
            prev[t] = t%arr[0]==0?t/arr[0]:1e9;
        }
        for(int i=1; i< n; i++){
            for(int t=1; t<=target ; t++){
                int notTake = prev[t];
                 int take = 1e9;
                 if(arr[i]<= t)
                      take = curr[t-arr[i]] + 1;
            curr[t] = min(take , notTake);
            }
            prev=curr;
        }
        return prev[target];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // return rec(coins.size()-1 , coins , amount);
        // vector<vector<int>>dp(coins.size() , vector<int>(amount+1 , -1));
        // int ans =  memo(coins.size()-1 , coins , amount , dp);
        // int ans = tabulation(coins , amount);
        int ans = spaceOptimization(coins , amount);
        return ans == 1e9 ? -1 : ans;
    }
};
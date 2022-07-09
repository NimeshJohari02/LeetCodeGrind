class Solution {
public:
 // DP + Memo Gives TLE . 
    int tabulation(vector<int>&nums , int k ){
        int n = nums.size() ;
        vector<int>dp(n+1 , 0 ) ;
        dp[n-1] = nums[n-1];
        for(int idx = n-1 ; idx>=0 ; idx--){
            int ans = INT_MIN;
            for(int j = 1; j <= k ; j++){
            ans = max(ans , nums[idx] +dp[idx+j]);
        }
         dp[idx] = ans ;
        }
        return dp[0];
    }
    int helper(int idx , vector<int>&nums , int k , vector<int>&dp){
        if(idx>=nums.size()-1) return dp[nums.size()-1]=nums[nums.size()-1];
        int ans = INT_MIN;
        if(dp[idx]!= -1) return dp[idx];
        for(int j = 1; j <= k ; j++){
            ans = max(ans , nums[idx] + helper(idx+j , nums  , k, dp));
        }
         return dp[idx] = ans ;
    }
    int solUsingMultiSet(vector<int>&nums , int k){
        int n = nums.size();
        vector<int>dp(n , INT_MIN);
        dp[0] = nums[0];
        multiset<int> s;
        s.insert(dp[0]);
        for(int i=1 ; i < n ; i++){
            if(i > k) s.erase(s.find(dp[i-k-1]));
            s.insert(dp[i] = *rbegin(s) + nums[i]);
        }
        return dp.back();
    }
    int maxResult(vector<int>& nums, int k) {
        // int n = nums.size() ;
        // vector<int>dp(n+1 , -1 );
        // return helper(0 , nums , k , dp);
        return solUsingMultiSet(nums , k );
    }
};


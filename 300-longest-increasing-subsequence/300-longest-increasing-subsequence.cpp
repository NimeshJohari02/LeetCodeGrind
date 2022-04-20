class Solution {
public:
    int rec(int i , int prev_i , vector<int>&nums){
        if(i==nums.size()) return 0;
        int notTake = rec(i+1 , prev_i , nums);
        int take = INT_MIN;
        if(prev_i == -1 || nums[i]> nums[prev_i])
            take = 1+ rec(i+1 , i , nums);
        return max(take , notTake);
    }
    int memo(int i , int prev_i , vector<int>&nums , vector<vector<int>>&dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
        int notTake = memo(i+1 , prev_i , nums , dp);
        int take = INT_MIN;
        if(prev_i == -1 || nums[i] > nums[prev_i])
            take = 1+ memo(i+1 , i , nums , dp);
        return dp[i][prev_i+1] = max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        // return rec(0 , -1 , nums);
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size() +1 , -1));
        return memo(0 , -1 , nums , dp);
    }
};
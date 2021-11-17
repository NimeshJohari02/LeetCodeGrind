class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 1);
        dp[0]=1;
        for(int i =1 ; i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i])
                {
                    dp[i]= max(dp[j]+1,dp[i]);
                }
            }
        }
        int mn = INT_MIN;
        for(auto it : dp)
        {
            mn = max(mn , it);
        }
        return mn;
    }
};
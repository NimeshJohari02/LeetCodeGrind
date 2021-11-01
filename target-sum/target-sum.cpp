class Solution {
public:
    int knapsack(vector<int> &nums , int target){
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = target; j >= nums[i]; --j) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[target];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(auto it : nums)
            sum+=it;

        int neededSum = (sum + target)/2;
        	if ((sum + target) % 2 == 1 || target > sum || target < -sum) return 0;
        return knapsack(nums , neededSum);
    }
};
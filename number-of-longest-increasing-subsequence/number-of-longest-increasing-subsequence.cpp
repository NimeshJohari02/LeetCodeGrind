class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
 int n = nums.size(), maxlen = 1, ans = 0;
        vector<int> NumberOfIncreasingSubsquencs(n, 1), dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        NumberOfIncreasingSubsquencs[i] = NumberOfIncreasingSubsquencs[j];
                    }
                    else if (dp[j]+1 == dp[i]) 
                        NumberOfIncreasingSubsquencs[i] += NumberOfIncreasingSubsquencs[j];
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        for (int i = 0; i < n; i++) 
            if (dp[i] == maxlen) ans += NumberOfIncreasingSubsquencs[i];
        return ans;
    }
};
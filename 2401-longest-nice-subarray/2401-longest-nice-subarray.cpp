class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int currAnd = 0, i = 0, ans = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
            while ((currAnd & nums[j]) > 0)
                currAnd  ^= nums[i++];
            currAnd |= nums[j];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     if (k <= 1) return 0;
        int pro = 1, ans = 0, i = 0;
        for (int j = 0; j < nums.size(); j++) {
            pro *= nums[j];
            while (pro >= k){   
                pro /= nums[i++];
            }
            ans += (j-i+1);
        }
        return ans;
    }
};
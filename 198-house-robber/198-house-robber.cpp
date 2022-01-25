class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for(int i=1 ; i <n ; i++){
            int pick = nums[i] + (i-2 >=0 ? prev2 : 0);
            int np = prev;
            int curr = max(pick , np);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
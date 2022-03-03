class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        // 
        sort(nums.begin(),nums.end());
        int ans = nums.back()-nums[0];
        for(int i=0 ; i<nums.size()-1;i++){
            int n1 = nums[i];
            int n2 = nums[i+1];
            int high = max(nums.back()-k,n1+k);
            int low = min(nums[0]+k,n2-k);
            ans = min(ans , high-low);
        }
        return ans;
    }
};
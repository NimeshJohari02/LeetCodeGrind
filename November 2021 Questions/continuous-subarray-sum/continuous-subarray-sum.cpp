class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(), prev=0;
        int sum=0;
        map<int,int> mp;
        for (int i=0; i<n; i++){
            sum = (sum + nums[i]) % k;  
            if (mp[sum]) return true;
            mp[prev] ++;
            prev = sum;
        }
        return false;
}
};

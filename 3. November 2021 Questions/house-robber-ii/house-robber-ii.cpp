class Solution {
public:
    int robHouseOne(vector<int>&nums){
        int n = nums.size();
        int include = nums[0];
        int exclude= 0;
        for(int i =1; i<=n-2;i++){
            int newInclude = exclude+nums[i];
            int newExclude = max(include , exclude);
            include= newInclude;
            exclude = newExclude;
        }
        return max(include , exclude);
    }
    int robHouseTwo(vector<int>&nums){
        int n = nums.size();
        int include = nums.size()>1?nums[1]:0;
        int exclude= 0;
        for(int i=2; i<=n-1;i++){
            int newInclude = exclude+nums[i];
            int newExclude = max(include , exclude);
            include= newInclude;
            exclude = newExclude;
        }
        return max(include , exclude);
    }
    int rob(vector<int>& nums) {
        return max(robHouseOne(nums), robHouseTwo(nums));
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int include=nums[0];
        int exclude=0;
        for(int i = 1 ; i < nums.size(); i++){
            int newInclude = exclude+nums[i];
            int newExclude = max(include , exclude);
            include=newInclude;
            exclude=newExclude;
        }
        return max(include,exclude);
    }
};
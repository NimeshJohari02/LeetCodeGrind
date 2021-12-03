class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums , vector<int>&subset , int index , int target){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        for(int i=index ; i<nums.size() ; i++)
        {
            if(target>=nums[i]){
            subset.push_back(nums[i]);
            helper(nums, subset , i, target-nums[i]);
            subset.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
        helper(candidates,subset,0,target);
        return ans;
    }
};
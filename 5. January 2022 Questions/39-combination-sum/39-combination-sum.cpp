// Solution Based On Pick / Not Pick Logic 
class Solution {
     private : 
    vector<vector<int>>ans;
    void helper(int idx , vector<int>&subset , vector<int>&arr , int target){
        if(idx == arr.size()){
            if(target ==0 )
                ans.push_back(subset);
            return;
        }
        if(arr[idx] <= target){
        subset.push_back(arr[idx]);
        helper(idx, subset , arr  , target-arr[idx]);
        subset.pop_back();
        }
        helper(idx +1 , subset , arr  , target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
        helper(0 , subset , candidates , target);
        return ans;
    }
};
/*
Prev Solution Based On Pick / Not Pick Using For Loop  
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
*/
class Solution {
public:
    vector<vector<int>> ans ;
    void helper(int idx , vector<int>&nums ){
    if(idx == nums.size()) {
        ans.push_back(nums);
        return ;
    }
       for(int i=idx ; i < nums.size() ; i++){
           swap(nums[i] , nums[idx]);
           helper(idx+1 , nums );
           swap(nums[i] , nums[idx]);
       }
       return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(0 , nums);
        return ans;
    }
};
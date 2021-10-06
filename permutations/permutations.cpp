class Solution {
public:
    vector<vector<int>>ans;
    void getPermutation(vector<int>nums , int i=0){
        if(i==nums.size()-1){
            ans.push_back(nums);
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            getPermutation(nums,i+1);
            //Backtrack
            swap(nums[i],nums[j]);
        }
    return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        getPermutation(nums,0);
        return ans;
    }
};
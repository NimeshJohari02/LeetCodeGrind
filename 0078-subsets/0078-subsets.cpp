class Solution {
    private : 
    vector<vector<int>>ans ;
    void soln(int idx , vector<int>&ds , vector<int>&nums){
        if(idx==nums.size()){
            ans.push_back(ds);
            return ;
        }
        ds.push_back(nums[idx]);
        soln(idx+1 , ds , nums);
        ds.pop_back();
        soln(idx+1 , ds , nums);
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds ;
        soln(0 , ds , nums);
        return ans ;
    }
};
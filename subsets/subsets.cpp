class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>nums,vector<int>output){
        if(nums.size()==0){
            ans.push_back(output);
            return;
        }
        vector<int>c1(output.begin(),output.end());
        vector<int>c2(output.begin(),output.end());
        c2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        helper(nums,c1);
        helper(nums,c2);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        helper(nums,v);
        return ans;
    }
};
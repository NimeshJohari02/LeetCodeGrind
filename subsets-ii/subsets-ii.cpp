class Solution {
public:
    set<vector<int>>ans;
    void helper(vector<int>nums , vector<int>output ){
    if(nums.empty()){
        // sort(output.begin(),output.end());
        ans.insert(output);
        return;
    }
        vector<int>op1(output.begin(),output.end());
        vector<int>op2(output.begin(),output.end());
        op1.push_back(nums.back());
        nums.pop_back();
        helper(nums , op1);
        helper(nums , op2);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr;
        sort(nums.begin(),nums.end());
        vector<int>dummy;
        helper(nums,dummy);
        for(auto it : ans){
            arr.push_back(it);
        }
        return arr;
    }
};
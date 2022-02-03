class Solution {
public:
    map<int,int>mp;
    vector<vector<int>>ans;
    void helper(int idx , vector<int>&nums , vector<int>&subset){
        if(idx == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        for(auto& v : mp){
            if(v.second!=0){
                v.second--;
                subset.push_back(v.first);
                helper(idx+1 , nums , subset);
                v.second++;
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int>subset;
    for(auto &it : nums)
        mp[it]++;
    helper(0 , nums , subset);
        return ans;
    }
};
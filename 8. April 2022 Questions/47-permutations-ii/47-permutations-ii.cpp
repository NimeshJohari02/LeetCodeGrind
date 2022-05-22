class Solution {
public:

    unordered_map<int , int> mp;
    vector<vector<int>>ans;
    void helper(int idx , vector<int>&ds , vector<int>&nums){
        if(idx == nums.size()){
            ans.push_back(ds);
            return ;
        }
        for(auto &it : mp){
            if(it.second!=0){
                it.second--;
                ds.push_back(it.first);
                helper(idx +1 , ds , nums);
                ds.pop_back();
                it.second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto &it : nums){
            mp[it]++;
        }
        vector<int>ds;
        helper(0 , ds , nums );
        return ans;
    }
};
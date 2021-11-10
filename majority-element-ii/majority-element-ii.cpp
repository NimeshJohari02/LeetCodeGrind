class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        vector<int>ans;
        int reqSize = nums.size()/3;
        for(auto it : mp){
            if(it.second > reqSize){
                ans.push_back(it.first);
            }
        }
    return ans;
    }
};
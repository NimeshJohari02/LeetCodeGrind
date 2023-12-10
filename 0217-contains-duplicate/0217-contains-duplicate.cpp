class Solution {
public:
    bool setAns(vector<int>&nums){
        return nums.size()>set<int>(nums.begin() , nums.end()).size();
    }
    bool mapAns(vector<int>&nums){
            map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        for(auto&it:mp) if(it.second>=2)return true;
        return false ;
    }
    bool containsDuplicate(vector<int>& nums) {
        return mapAns(nums);
    
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      map<int,int>mp;
      for(auto x:nums){
        mp[x]++;
      }
      for(auto it = mp.begin();it!=mp.end();it++){
        if(it->second>1){
          return true;
        }
      }
      return false;
    }
};
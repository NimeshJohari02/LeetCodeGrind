class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int currSum =0;
      int count;
      unordered_map<int,int>storeMap;
      storeMap[0]++;
      for(auto i : nums){
        currSum+=i;
        count+=storeMap[currSum-k];
        storeMap[currSum]++;
      }
      return count;
    }
};
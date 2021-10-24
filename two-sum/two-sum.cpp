class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
      map<int,int>visitedMap;
      vector<int> ans;
      for(int i=0;i<nums.size();i++){
        if(visitedMap[target-nums[i]]){
          ans.push_back(i);
          ans.push_back(visitedMap[target - nums[i]]-1);
        }  
        visitedMap[nums[i]]=i+1;
      }
      return ans;
    }
};
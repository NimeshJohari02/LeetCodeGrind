class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0;
      for(auto x : nums ){
        s+=x;
      }
      int n = nums.size();
      return ((n*(n+1))/2-s);
    }
};
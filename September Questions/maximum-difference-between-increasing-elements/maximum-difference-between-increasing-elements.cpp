class Solution {
public:
    int maximumDifference(vector<int>& nums) {
      int currMax=-1;
      for(int i=0;i<=nums.size()-2;i++){
        for(int j=i+1;j<=nums.size()-1;j++)
        {
          if(nums[j]>nums[i]){
            currMax=max(nums[j]-nums[i],currMax);
          }
        }
        }
      return currMax;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ln =0;
      for(auto it:nums){
        if(it!=0){
          nums[ln++]=it;
        }
      }
      for(int i=ln;i<nums.size();i++){
        nums[i]=0;
      }
    }
};
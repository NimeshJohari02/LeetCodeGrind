class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int firstOccuranceIdx=0;
      int k =0;  
      for(int i=1;i<nums.size();i++){
          if(nums[i]==nums[firstOccuranceIdx]){
            nums[i]=INT_MAX;
            k++;
          }
          else{
            firstOccuranceIdx=i;
          }
        }
        sort(nums.begin(),nums.end());
      return nums.size()-k;
        }
};
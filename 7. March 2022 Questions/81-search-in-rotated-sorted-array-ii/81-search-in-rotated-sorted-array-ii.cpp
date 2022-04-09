class Solution {
public:
    bool search(vector<int>& nums, int target) {
     int l =0, r = nums.size()-1;
    int mid = 0;
        if(nums.size()==1){
            return nums[0]==target;
        }
    while(l<=r){
          mid=(l+r)/2;
          if(nums[mid]==target) return true;
         
        if(nums[mid]>nums[r]){
              if(nums[mid]>target && nums[l] <= target) r = mid;
              else l = mid + 1;
          }
        // Pivot Lies Left 
        else if(nums[mid] < nums[r]){
              if(nums[mid]<target && nums[r] >= target) l = mid + 1;
              else r = mid;
          }
        //Nor
        else{
              r--;
          }
          
    }
    return nums[l] == target ;
    }
};
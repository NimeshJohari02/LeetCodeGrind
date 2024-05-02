class Solution {
public:
    int iterative(vector<int>&nums , int target){
                int s = 0 , e= nums.size()-1 ;
        while(e >= s ){
            int mid = (e+s)/2 ;
            if(nums[mid]==target)return mid ;
            else if(nums[mid]>target) e = mid-1 ;
            else s = mid+1;
        }
        return -1 ;
    }
    int recursive(vector<int>&nums , int s , int e , int target){
        if(s > e)return -1 ;
        int mid =(s+e) /2 ;
        if(nums[mid]==target)return mid ;
        else if(nums[mid]>target) return recursive(nums , s , mid-1 , target);
        else return recursive(nums , mid+1 , e , target);
    }
    int search(vector<int>& nums, int target) {
        return recursive(nums , 0 , nums.size()-1 , target);
    }
};
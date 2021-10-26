class Solution {
public:
    // This is recursive approach will definitely give TLE . Now Memoizing this 
   /* int arr[100000];
    bool helper(vector<int>&nums , int pos=0){
         if(pos == nums.size()-1){
             arr[pos]=1;
            return true;
        }
        if(arr[pos]!=-1){
            if(arr[pos]==0){
                return false;
            }
            return true;
        }
        int currJump = nums[pos];
        bool  canReachEndByTakingIJump = false;
        for(int i =1 ; i<=currJump ; i++){
            if(pos+i<=nums.size()-1){
             canReachEndByTakingIJump = helper(nums,pos+i);
            }
            if(canReachEndByTakingIJump){
                arr[pos+i]=1;
                return true;
            }
        }
        arr[pos]=0;
        return false;
    }
    // Even After Memoization the Runtime is quite bad 
    // Approach Optimised -> take a max reach element , This indicate to which position have you reached starting from i .
    // At the end check if max Reach. In this greedy would also work that you are taking the maximum jump . If in the end you are 
    // able to reach the maximum element then you can definitely take jumps from 1 -> max 
    */
    bool canJump(vector<int>& nums) {
        int i =0;
        for( int maxReach=0; i <nums.size() &&  i <= maxReach ;i++){
            maxReach = max(i+nums[i], maxReach);
        }
        return i == nums.size();
    }
    
    
};

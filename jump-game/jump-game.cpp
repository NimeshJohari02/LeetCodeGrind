class Solution {
public:
    // This is recursive approach will definitely give TLE . Now Memoizing this 
    int arr[100000];
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
    bool canJump(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        return helper(nums);
    }
};
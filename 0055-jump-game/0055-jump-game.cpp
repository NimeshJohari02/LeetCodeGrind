class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximumReach  = 0;
        if(nums.size()==1) return true ; 
        int i=0;
        for(; i < nums.size() && i <= maximumReach ; i++)
            maximumReach = max(maximumReach , i+nums[i]);
        
        return i==nums.size() ;
    }
};
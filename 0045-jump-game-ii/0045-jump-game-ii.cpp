class Solution {
public:
    int greedySolution(vector<int>&nums){
                int ans = 0 ,  end = 0 , maxReach = 0 ;
        // Since it is already said that we can reach the last element we need not consider            the jump last element provides We need to reach last element not jump from last              element   
        // also. So reduce the size of the array by 1 . 
        for(int i=0 ; i < nums.size()-1; i++){
            maxReach = max(maxReach , i + nums[i]);
            if(i==end){
                ans++ ;
                end = maxReach ;
            }
        }
        return ans ; 
    }
    int recursive(int idx , vector<int>&nums){
        if(idx>=nums.size()-1)return 0;
        int minJumps = 1e5;
        for(int j = 1 ; j <= nums[idx];j++)
            minJumps = min(minJumps , 1+recursive(idx+j,nums));
        return minJumps;
    }
    int memoization(int idx , vector<int>&nums , vector<int>&dp){
        if(idx>=nums.size()-1) return 0 ;
        if(dp[idx]!= 1e5)return dp[idx];
        int minJumps = 1e5 ;
        for(int j=1 ; j <=nums[idx];j++)
            minJumps = min(minJumps , 1+memoization(idx+j ,nums , dp));
        return dp[idx] = minJumps ;
    }
    int jump(vector<int>& nums) {
        // return recursive(0 , nums);
        vector<int>dp(nums.size() , 1e5);
        return memoization(0 , nums , dp);
    }
};
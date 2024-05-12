class Solution {
public:
    bool dpPartition(vector<int>&nums , int k){
        int n = nums.size();
        vector<vector<bool>>dp(n, vector<bool>(k+1 , false));
        // 1st col target 0 can be reached from anyidx 
        for(int i=0 ; i <n ; i++) dp[i][0] = true ;
        // if(k <= nums[0])dp[0][nums[0]] = 1 ;
        for(int i=1 ; i<=n-1 ; i++){
            for(int target = 1 ; target <= k ;target++){
                // Pick not Pick logic ;
                int pick=0 , notPick =0 ;
                if(target>=nums[i]) pick = dp[i-1][target-nums[i]];
                notPick = dp[i-1][target];
                dp[i][target] = pick || notPick;
            }
        }
        return dp[n-1][k];
    }
    bool canPartition(vector<int>& nums) {             
        int sum = 0 ;
        if(nums.size()==1)return false ;
        for(auto &it : nums)sum+=it;
        if(sum&1)return false ;
        else return dpPartition(nums , sum/2);
    }
};

// Dry run for the case 9 , 5 

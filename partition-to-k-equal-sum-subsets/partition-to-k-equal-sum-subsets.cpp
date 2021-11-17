// class Solution {
// public:
//      int canPartition(vector<int>nums , int target){
//         int dp[nums.size()+1][target+1];
//         for(int i =0 ; i < target+1;i++){
//             dp[0][i]=0;
//         }
//         for(int i =0 ; i < nums.size()+1;i++){
//             dp[i][0]=1;
//         }
//         for(int i =1 ; i<= nums.size();i++){
//             for(int j = 1 ; j <= target ; j++){
//                 if(nums[i-1]<=j){
//                     dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
//                 }
//                 else{
//                     dp[i][j]=dp[i-1][j];
//                 }
                
//             }
//         }
//         return dp[nums.size()][target];
//     }

//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum =0;
//         for(auto it : nums){
//             sum+=it;
//         }
//         cout<<"Sum = "<<sum<<endl;
//         cout<<canPartition(nums , sum / k);
//         return true;
//     }
// };
// Reference article https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/335668/DP-with-Bit-Masking-Solution-%3A-Best-for-Interviews
class Solution {
public:
    int dp[(1<<16)+2];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};
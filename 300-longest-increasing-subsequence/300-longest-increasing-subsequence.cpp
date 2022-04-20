// class Solution {
// public:
//     int rec(int i , int prev_i , vector<int>&nums){
//         if(i==nums.size()) return 0;
//         int notTake = rec(i+1 , prev_i , nums);
//         int take = INT_MIN;
//         if(prev_i == -1 || nums[i]> nums[prev_i])
//             take = 1+ rec(i+1 , i , nums);
//         return max(take , notTake);
//     }
//     int memo(int i , int prev_i , vector<int>&nums , vector<vector<int>>&dp){
//         if(i == nums.size()) return 0;
//         if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
//         int notTake = memo(i+1 , prev_i , nums , dp);
//         int take = INT_MIN;
//         if(prev_i == -1 || nums[i] > nums[prev_i])
//             take = 1+ memo(i+1 , i , nums , dp);
//         return dp[i][prev_i+1] = max(take , notTake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         // return rec(0 , -1 , nums);
//         vector<vector<int>>dp(nums.size(), vector<int>(nums.size() +1 , -1));
//         return memo(0 , -1 , nums , dp);
//     }
// };

class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>dp(n , 1);
    //     dp[0]=1;
    //     for(int i =1 ; i<nums.size();i++){
    //         for(int j=i-1;j>=0;j--){
    //             if(nums[j]<nums[i])
    //             {
    //                 dp[i]= max(dp[j]+1,dp[i]);
    //             }
    //         }
    //     }
    //     int mn = INT_MIN;
    //     for(auto it : dp)
    //     {
    //         mn = max(mn , it);
    //     }
    //     return mn;
    // }
    int lengthOfLIS(vector<int>&arr){
        vector<int>temp;
        int n = arr.size();
        temp.push_back(arr[0]);
        for(int i=1 ; i < n ; i++){
            if(arr[i] > temp.back())
                temp.push_back(arr[i]);
            else{
                int idx = lower_bound(temp.begin() , temp.end() , arr[i]) - temp.begin();
                temp[idx] = arr[i];
            }
        }
        return temp.size();
    }
};


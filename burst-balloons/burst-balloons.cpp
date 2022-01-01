
class Solution {
public:
    int dp[502][502];
    int maxCoins(vector<int>& nums) {
        // Insert 1 at both ends as setinel value denoting cases when i == 0 or j==nums.size() ;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return solve(nums,1,nums.size()-1);
    }
    
    int solve(vector<int> &nums, int i, int j){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = INT_MIN;
        for(int k = i;k <= j-1;k++){
            int temp = solve(nums,i,k) + solve(nums,k+1,j) + nums[i-1]*nums[k]*nums[j];
            mn = max(mn , temp);
        }
        dp[i][j] = mn;
        return dp[i][j];
    }
};
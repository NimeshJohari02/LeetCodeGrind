class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+1,0);
        //! Note We have to use unsigned int because even long long gives an error 
        dp[0]=1;
        for(int i=1 ; i<=target ; i++){
            for(auto it: nums){
                if(i>=it){
                    dp[i]+=dp[i-it];
                }
            }
        }
        return dp[target];
    }
};
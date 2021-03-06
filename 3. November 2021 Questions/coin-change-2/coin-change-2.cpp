class Solution {
public:
    int change(int amount, vector<int>& nums) {
        int dp[nums.size()+1][amount+1];
        for(int i =0 ; i <= amount ; i++){
            dp[0][i]=0;
        }
        for(int i =0 ; i <= nums.size();i++ ){
            dp[i][0]=1;
        }
        
        for(int i =1 ; i <= nums.size(); i++){
            for(int j = 1 ; j <=amount; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j]+dp[i][j-nums[i-1]]; 
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][amount];
        
    }
};
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>>dp(row , vector<int>(col,0));
         int ans=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            dp[i][j] = matrix[i][j]-'0';
            if(dp[i][j]==1)
                ans = 1;
        }
            
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++)
            if(dp[i][j]==1){
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                ans = max(ans,dp[i][j]);
            }
    }
    
    return ans * ans;
        }
};
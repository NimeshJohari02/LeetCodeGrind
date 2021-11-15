class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0 ; i<matrix[0].size();i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1 ; i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int top = dp[i-1][j];
                int topLeft = j>=1?dp[i-1][j-1]:INT_MAX;
                int topRight = j+1<matrix[i].size()?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min(min(top,topLeft),topRight);
            }
        }
        int ans =INT_MAX;
        for(auto it : dp.back()){
            ans=min(it,ans);
        }
    return ans;
    }
};
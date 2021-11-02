// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& arr) {
//         int row = arr.size();
//         int col = arr[0].size();
        
//         int dp[row][col];
//         dp[0][0]=arr[0][0]==1?0:1;
        
//         for(int i =1 ; i< row;i++){
//             dp[i][0]=1 * !(arr[i][0]) *dp[i-1][0];
//         }
//         for(int i =1 ; i<col;i++)
//         {
//             dp[0][i]=1 * !(arr[0][i]) * dp[0][i-1];
//         }
        
//         for(int i=1;i<row;i++){
//             for(int j=1;j<col;j++){
//                 if(arr[i][j]==1){
//                     dp[i-1][j]/=2;
//                     dp[i][j-1]/=2;
//                 }
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
                
//             }
//         }
        
//          for(int i =0 ; i < row;i++){
//             for(int j=0;j<col;j++){
//                cout<<dp[i][j]<<"  ";
//             }
//              cout<<"\n";
//         }
        
//         return dp[row-1][col-1];
//     }
// };
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    } 
};
class Solution {
public:

  int recursion( vector<vector<int>>& obstacleGrid , int row, int cols) {
    if (row == 0 && cols == 0) return 1;
      if(row>=0 && cols >=0 && obstacleGrid[row][cols]==1 ) return 0;
    if (row < 0 || cols < 0) return 0;
    int pathUp = recursion( obstacleGrid , row - 1, cols);
    int pathLeft = recursion(obstacleGrid , row, cols - 1);
    return pathLeft + pathUp;
  }
  int uniquePathsMemoized(vector<vector<int>>& obstacleGrid , int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return dp[i][j] = 1;
    if (i < 0 || j < 0) return 0;
    if(i>=0 && j >=0 && obstacleGrid[i][j]==1 ) return 0;
      
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = uniquePathsMemoized(obstacleGrid ,i - 1, j, dp) +
                      uniquePathsMemoized(obstacleGrid , i, j - 1, dp);
  }
  int uniquePathBottomUp(vector<vector<int>>& obstacleGrid , int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
      if(obstacleGrid[0][0]==1)return 0;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
          continue;
        }
        if(obstacleGrid[i][j] == 1) {dp[i][j] = 0; continue;} 
        int up = j - 1 >= 0 ? dp[i][j - 1] : 0;
        int left = i - 1 >= 0 ? dp[i - 1][j] : 0;
        dp[i][j] = up + left;
      }
    }
    return dp[m - 1][n - 1];
  }

    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      return uniquePathBottomUp(obstacleGrid , obstacleGrid.size() , obstacleGrid[0].size());
    }
};
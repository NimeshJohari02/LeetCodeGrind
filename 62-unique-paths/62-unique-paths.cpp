class Solution {
 public:
  int uniquePaths(int m, int n) {
    // vector<vector<int>>dp(m , vector<int>(n , -1));
    // return uniquePathsMemoized(m-1, n-1, dp);
    return uniquePathBottomUpSpaceOptimized(m, n);
  }
  int recursion(int row, int cols) {
    if (row == 0 && cols == 0) return 1;
    if (row < 0 || cols < 0) return 0;
    int pathUp = recursion(row - 1, cols);
    int pathLeft = recursion(row, cols - 1);
    return pathLeft + pathUp;
  }
  int uniquePathsMemoized(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return dp[i][j] = 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = uniquePathsMemoized(i - 1, j, dp) +
                      uniquePathsMemoized(i, j - 1, dp);
  }
  int uniquePathBottomUp(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
          continue;
        }
        int up = j - 1 >= 0 ? dp[i][j - 1] : 0;
        int left = i - 1 >= 0 ? dp[i - 1][j] : 0;
        dp[i][j] = up + left;
      }
    }
    return dp[m - 1][n - 1];
  }
    int uniquePathBottomUpSpaceOptimized(int m , int n ){
    vector<int>prev(n , 0);
    for(int i=0 ; i < m ; i++){
        vector<int>currentRow(n , 0);
        for(int j=0 ;j < n ; j++){
            if(i==0 && j ==0 ) {currentRow[0]=1;continue;} 
            int left =j-1 >=0 ? currentRow[j-1] : 0;
            int up =  prev[j] ;
            currentRow[j] = up + left;
        }
        prev = currentRow ;
    }
    return prev[n-1];
}

    
};
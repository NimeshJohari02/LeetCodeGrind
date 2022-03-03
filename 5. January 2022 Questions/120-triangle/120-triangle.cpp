class Solution {
 public:
  int triangleTabulation(vector<vector<int>> &grid) {
    int r = grid.size();
    int c = r;
    vector<vector<int>> dp(r, vector<int>(r, 0));
    for (int j = 0; j < c; j++) {
      dp[r - 1][j] = grid[r - 1][j];
    }
    for (int i = r - 2; i >= 0; i--) {
      for (int j = i; j >= 0; j--) {
        int d = grid[i][j] + dp[i + 1][j];
        int dr = grid[i][j] + dp[i + 1][j + 1];
        dp[i][j] = min(d, dr);
      }
    }
    return dp[0][0];
  }
  int recmem(int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    if (r == arr.size() - 1) return arr[r][c];
    if (dp[r][c] != -1) return dp[r][c];
    int d = arr[r][c] + arr[r + 1][c];
    int dg = arr[r][c] + arr[r + 1][c + 1];
    return dp[r][c] = min(d, dg);
  }
  int tabulationSpaceOptimized(vector<vector<int>> &arr) {
    int n = arr.size();
    vector<int> lowerRow(n, 0);
    for (int j = 0; j < n; j++) {
      lowerRow[j] = arr[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--) {
      vector<int> curr(n, 0);
      for (int j = i; j >= 0; j--) {
        int d = arr[i][j] + lowerRow[j];
        int dg = arr[i][j] + lowerRow[j + 1];
        curr[j] = min(d, dg);
      }
      lowerRow = curr;
    }
    return lowerRow[0];
  }
  int rec(int r, int c, vector<vector<int>> &arr) {
    if (r == arr.size() - 1) return arr[r][c];
    int down = arr[r][c] + rec(r + 1, c, arr);
    int right = arr[r][c] + rec(r + 1, c + 1, arr);
    return min(down, right);
  }

  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.size() == 1) {
      return triangle[0][0];
    }
    // return rec(0, 0, triangle);
    // return triangleTabulation(triangle);
    return tabulationSpaceOptimized(triangle);
  }
};
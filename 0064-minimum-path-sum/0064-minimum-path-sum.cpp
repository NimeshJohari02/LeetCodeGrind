class Solution {
public:
    int recursion(int i , int j , vector<vector<int>>&grid, vector<vector<int>>&dp ){
        int n = grid.size() , m = grid[0].size();
        if(i>=grid.size() || j >= grid[0].size() || i < 0 || j < 0 ) return 1e5;
        if(i == n-1 && j == m-1)return dp[i][j]= grid[i][j];
        if(dp[i][j] !=1e5) return dp[i][j];
        int bottom = grid[i][j] + recursion(i+1, j, grid ,dp);
        int down = grid[i][j] + recursion(i, j+1 , grid ,dp);
        return dp[i][j] = min(down , bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>dp(n , vector<int>(m , 1e5));
        return recursion(0 , 0 , grid,dp);
    }
};
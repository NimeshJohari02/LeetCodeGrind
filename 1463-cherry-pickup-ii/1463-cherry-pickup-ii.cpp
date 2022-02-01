class Solution {
public:
    int dp[70][70][70] = {};
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m, n, 0, 0, n - 1);
    }
    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        if (r == m) return 0; // Reach to bottom row
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans + cherries;
    }
};
// This is the memoized Solution
class Solution {
public:
    int dp[71][71][71];
    int memoize(int i , int j1 , int j2 , vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j1 < 0 || j2<0 || i >= n|| j1 >=m|| j2>=m  )return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return (grid[i][j1] + grid[i][j2]);
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e8;
        for(int r1= -1 ; r1<=1;r1++){
            for(int r2 = -1 ; r2<=1 ; r2++){
                int value =0;
                if(j1==j2){
                    value = grid[i][j1];
                }
                else{
                    value =  grid[i][j1]+grid[i][j2];
                }
                value+=memoize(i+1 , j1+r1 , j2+r2 , grid);
                maxi = max(maxi , value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int cols = grid[0].size();
        memset(dp , -1 ,sizeof(dp));
        
        return memoize(0 , 0 , cols-1 , grid);
        
    }
};

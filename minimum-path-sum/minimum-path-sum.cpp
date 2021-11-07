class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int row = grid.size() ;
        int col = grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int i=0 ; i <row ; i++ ){
            dp[i][0]=i==0?grid[i][0]:grid[i][0]+dp[i-1][0];
        }
          for(int j=0 ; j <col ; j++ ){
            dp[0][j]=j==0?grid[0][j]:grid[0][j]+dp[0][j-1];
        }
        for(int i=1 ; i <row ; i++)
            for(int j = 1 ; j < col ; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i][j]; 
            }
    for(auto it : dp){
        for(auto i : it){
            cout<<i<<"  ";
        }
        cout<<"\n";
    }
    return dp[row-1][col-1];
    }
};



// Another approach using only a single vector because we want to keep track of only prev row 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),0));
        int m=101;
        int sm =101;
        for(int i=0 ; i<n;i++)
        {
//             minimum = min(minimum , grid[0][i]);
            if(grid[0][i]<=m){
                sm = m ;
                m = grid[0][i];
            }else if(grid[0][i]<=sm){
                sm=grid[0][i];
            }
            dp[0][i]=grid[0][i];
        }
        for(int i=1 ; i<n ;i++){
            int nm=INT_MAX;
            int nsm = INT_MAX;
            for(int j =0 ; j<n ; j++){
                // dp[i][j]= arr[i][j] ;
                
                
                if(dp[i-1][j]==m){
                    dp[i][j]=grid[i][j]+sm;
                }
                else{
                    dp[i][j]=grid[i][j]+m;
                }
                
                if(dp[i][j]<=nm){
                nsm = nm ;
                nm = dp[i][j];
            }else if(dp[i][j]<=nsm){
                nsm=dp[i][j];
            }
            }
            m=nm;
            sm=nsm;
        }
        return m;
    }
};
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
         int left[n][n];
         int right[n][n];
         int up[n][n];
         int down[n][n];
         int size = sizeof(left)/sizeof(left[0][0]);
        memset(&left[0][0],0,sizeof(left));
        memset(&right[0][0],0,sizeof(left));
        memset(&up[0][0],0,sizeof(left));
        memset(&down[0][0],0,sizeof(left));
        int grid[n][n];
        fill(&grid[0][0],&grid[0][0]+sizeof(grid)/sizeof(grid[0][0]),1);
        for(auto it : mines ){
        grid[it[0]][it[1]]=0;
      }
      
      for(int i=0;i<n;i++){
        int s =0;
        for(int j=0;j<n;j++){
          s+=grid[i][j];
        if(grid[i][j]==1){
          left[i][j]=s;
        }
          else{
          s=0;
          }
        }
      }
      for(int i=n-1;i>=0;i--){
        int s =0;
        for(int j=n-1;j>=0;j--){
        s+=grid[i][j];
        if(grid[i][j]==1){
          right[i][j]=s;
        }
          else{
          s=0;
          }
        }
      }
      
      for(int i=n-1;i>=0;i--){
        int s =0;
        for(int j=n-1;j>=0;j--){
          s+=grid[j][i];
        if(grid[j][i]==1){
          down[j][i]=s;
        }
          else{
          s=0;
          }
        }
      }
      for(int i=0;i<n;i++){
        int s =0;
        for(int j=0;j<n;j++){
          s+=grid[j][i];
        if(grid[j][i]==1){
          up[j][i]=s;
        }
          else{
          s=0;
          }
        }
      }
      int mx = INT_MIN;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          int val = min(min(min(down[i][j],up[i][j]),left[i][j]),right[i][j]);
            if(left[i][j]>=val && right[i][j]>=val && up[i][j]>=val && down[i][j]>=val){
              if(mx<val){
                mx=val;
              }
            }      
          }
      }
      return mx;
    }
  
};
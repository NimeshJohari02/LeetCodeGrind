class Solution {
private : 
    int dfs(int x , int y , vector<vector<int>>&grid ){
          int originalNumber=grid[x][y],result=0;
        // mark as visited using 0 as viisted .
        grid[x][y]=0;
        int dx[]= {1 , -1 , 0  , 0};
        int dy[] = {0 , 0 , 1 , -1};
        for(int k=0 ; k < 4 ; k++)                
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[x].size()&&grid[nx][ny]!=0)
                result=max(result,grid[nx][ny]+dfs(nx , ny , grid));  
        }
        grid[x][y]=originalNumber;
        return result;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans = 0;
        for(int i=0 ; i < n ; i++)
            for(int j =  0 ; j < m ; j++)
                if(grid[i][j]>0)
                    ans = max(grid[i][j]+dfs(i , j , grid ) , ans);
        return ans ;
    }
};
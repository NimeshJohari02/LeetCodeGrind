class Solution {
public:
    
    int bfs(vector<vector<int>>&grid , int row , int col){
        queue<pair<int , int >> q;
        int m = grid.size();
        int n = grid[0].size();
        q.push({ row , col});
        int area =1 ;
        grid[row][col] = 1e9;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dx[]={1 , -1 , 0 , 0};
            int dy[]={0 , 0 , 1 , -1};
            for(int i=0 ; i < 4 ; i++){
                int nx = node.first + dx[i];
                int ny = node.second+ dy[i];
                if(nx >=0 && ny >=0 && nx < m && ny < n && grid[nx][ny] ==1 )
                {
                    grid[nx][ny] = 1e9;
                    area++;
                    q.push({nx , ny});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        int ans = 0 ;
        for(int i=0 ; i < m ; i++)
            for(int j=0 ; j <n ; j++)
                if(grid[i][j]==1 ) ans = max(ans , bfs(grid , i , j));
        return ans;
    }
};
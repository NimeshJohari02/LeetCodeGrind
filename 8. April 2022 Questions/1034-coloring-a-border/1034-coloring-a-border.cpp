class Solution {
public:
    
    void dfs(vector<vector<int>>&grid , int row , int col , int color){
        grid[row][col] = -color;
        int dx[] = { 0 , 0 , 1 , -1};
        int dy[] = {1, -1 , 0 , 0};
        int count =0;
        for(int i=0  ; i < 4 ; i++){
            int nx = row+dx[i];
            int ny = col+dy[i];
            if(nx >=0 && ny >=0 && nx < grid.size() && ny <grid[0].size() && abs(grid[nx][ny]) == color){
                count++;
                if(grid[nx][ny] == color){
                    dfs(grid , nx , ny , color);
                }
            }
        }
        if(count == 4) grid[row][col] = color;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        dfs(grid , row , col , grid[row][col]);
        for(auto &it : grid)
            for(auto &iit : it)
                if(iit < 0)
                    iit = color;
        return grid;
    }
};
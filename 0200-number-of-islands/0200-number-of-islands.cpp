class Solution {
public:
    void DFS(int i , int j , vector<vector<char>>&grid){
         int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] ='0';
        DFS(i+1 ,j , grid);
        DFS(i ,j+1 , grid);
        DFS(i-1 ,j , grid);
        DFS(i ,j-1 , grid);
    }
    int dfsSol(vector<vector<char>>&grid){
        int m = grid.size(), n = m ? grid[0].size() : 0, ans = 0;
        for(int i=0 ; i < m ;i++){
            for(int j =0 ; j < n ; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    DFS(i , j , grid);
                }
            }
        }
        return ans ;
    }
    int bfsSol(vector<vector<char>>&grid){
        int m = grid.size(), n = m ? grid[0].size() : 0, ans = 0;
        queue<pair<int,int>>q ;
        int deltaX[]= {1 , -1 , 0 , 0};
        int deltaY[]= {0 , 0 , 1 , -1 };
        for(int i=0 ; i < m ; i++){
            for(int j =0 ; j < n ; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    grid[i][j]=0;
                    q.push({i , j});
                    while(!q.empty()){
                        auto [x , y] = q.front();
                        q.pop();
                        for(int k =0 ; k < 4 ;k++){
                            int dx = x+deltaX[k]; // row
                            int dy = y+deltaY[k]; // col
                            if(dx>=0 && dy>=0 && dx < m && dy< n && grid[dx][dy]=='1'){
                                grid[dx][dy]=0 ;
                                q.push({dx , dy});
                            }
                        }
                    }
                }
            }
        }
        return ans ;
    }
    int numIslands(vector<vector<char>>& grid) {
        // return bfsSol(grid);
        return dfsSol(grid);
    }
};
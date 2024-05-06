class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // Simple BFS;
        int n = grid.size() ; 
        queue<vector<int>>q; 
        q.push({1 , 0 , 0 });
            // dist , x , y ;
        if(grid[0][0]!=0)return -1 ;
        while(!q.empty())
        {
            auto vec = q.front();
            q.pop();
            int currCost = vec[0] , x = vec[1] , y = vec[2];
            if(x ==  n-1 && y == n-1) return currCost;
            int dx[] = {1 , 1, 1  , 0 , 0 , -1 , -1 , -1};
            int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0  , 1};
            for(int k=0 ; k < 8 ; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && nx < n && ny >=0 && ny < n && grid[nx][ny]==0){
                    q.push({currCost+1 , nx , ny});
                    // visited 
                    grid[nx][ny] = 2 ;
                }
            }
        }
        // nothing 
        return -1 ;
    }
};

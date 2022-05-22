class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();
        int m = grid[0].size();
        priority_queue< vector<int>  , vector< vector<int> > , greater< vector<int>>> pq;
        // 1 is length . 2 3 is x and y coordinate;
        if(grid[0][0] != 0) return -1;
        pq.push({1 , 0 , 0});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int cost = node[0] , x = node[1] , y = node[2];
            if(x ==  n-1 && y == m-1) return cost;
            int dx[] = {1 , 1, 1  , 0 , 0 , -1 , -1 , -1};
            int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0  , 1};
            for(int i=0 ; i < 8 ; i ++){
                int nx = x +dx[i];
                int ny = y +dy[i];
                if(nx>=0 && ny >=0 && nx < n && ny < m && grid[nx][ny]==0){
                    pq.push({cost +1 , nx , ny});
                    grid[nx][ny] = 2;
                }
            }
        }
     return -1;   
    }
};

// class Solution {
// public:
    
//     int swimInWater(vector<vector<int>>& grid) {
//         priority_queue<pair<int , pair<int , int >> ,vector<pair<int , pair<int , int >>>, greater<pair<int , pair<int , int>>>> pq;
//         // MAX SO FAR , ROW , COL;
//         int r = grid.size();
//         int c = grid[0].size();
//         pq.push({max(grid[0][0], grid[r-1][c-1]) , {0 , 0}});
//         vector<vector<bool>>visited(grid.size() , vector<bool>(grid[0].size() , false));
//         visited[0][0] = true;
//         int dx[] = {0 , 0 , 1 , -1};
//         int dy[] = {1 , -1 ,0 , 0};
//         while(!pq.empty()){
//             auto node = pq.top();
//             pq.pop();
//             int x = node.second.first;
//             int y = node.second.second;
//             if(x == r-1 && y == c-1) return node.first;
//             if(!visited[x][y]){
//                 visited[x][y] = true;
//                 for(int i=0 ; i < 4 ; i++){
//                     int nx = x+dx[i];
//                     int ny = y+dy[i];
//                     if(nx<0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny] ) continue;
//                     pq.push({max(node.first , grid[nx][ny]),{nx , ny}});
//                 // }
//             }
//         }
//         return 0 ;
//     }
// };
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if(grid.size() ==1 ) return grid[0][0];
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + dir[i], c = cur[2] + dir[i+1];
                if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    pq.push({grid[r][c], r, c});
                    visited[r][c] = 1;
                }
            }
        }
        return -1;
    }
};
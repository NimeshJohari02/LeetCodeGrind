class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m>0 ? grid[0].size() : 0;
        int ans = 0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0 ,0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int newX = p.first + dx[k];
                            int newY = p.second+dy[k];
                            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == '1') {
                                grid[newX][newY] = '0';
                                q.push({newX, newY});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
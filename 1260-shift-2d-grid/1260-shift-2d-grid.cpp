class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m * n; ++i) {
            int y = i / n , x = i % n;
            int ny = (y + (x + k) / n) % m , nx = (x + k) % n;
            ans[ny][nx] = grid[y][x];
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> temp;
        temp = grid;
        int n = grid.size(), m = grid[0].size();
        while(k--){
            for(int i = 0; i < n; ++i){
                for(int j = 1; j < m; ++j){
                    temp[i][j] = grid[i][j-1];
                }
                    
            }
            for(int i = 0; i < n-1; ++i){
                temp[i+1][0] = grid[i][m-1];
            }
            temp[0][0] = grid[n-1][m-1]; // special case
            grid = temp;
        }
        return temp;
    }
};


*/
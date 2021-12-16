class Solution {
public:
     vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                if (mat[r][c] == 0) q.push({r, c});
                else mat[r][c] = -1; 

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first ;
            int y = p.second;
            for (int i = 0; i < 4; ++i) {
                int nx = x + DIR[i], ny = y + DIR[i+1];
                if (nx < 0 || nx == row || ny < 0 || ny == col || mat[nx][ny] != -1) continue;
                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return mat;
    }
    
};




                   

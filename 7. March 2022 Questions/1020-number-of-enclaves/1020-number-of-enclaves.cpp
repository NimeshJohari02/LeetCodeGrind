class Solution {
 public:
  int numEnclaves(vector<vector<int>>& arr, int res = 0) {
    queue<pair<int, int>> q;
    for (auto i = 0; i < arr.size(); ++i)
      for (auto j = 0; j < arr[0].size(); ++j) {
        res += arr[i][j];
          // Boundary Ones Can Jump Off Thus Push into queue 
        if (i==0 || j==0  || i == arr.size() - 1 || j == arr[i].size() - 1)
          q.push({i, j});
      }
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      if (x < 0 || y < 0 || x == arr.size() || y == arr[x].size() ||
          arr[x][y] != 1)
        continue;
      arr[x][y] = 0;
      res--;
      int dx[] = {0, 0, 1, -1};
      int dy[] = {1, -1, 0, 0};
      for (int i = 0; i < 4; i++) {
        q.push({x + dx[i], y + dy[i]});
      }
    }
    return res;
  }
};
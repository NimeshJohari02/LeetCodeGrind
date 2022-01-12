
#include <bits/stdc++.h>
using namespace std;

class DSU {
 private:
  vector<int> parent, size;

 public:
  DSU(int n) {
    for (int i = 1; i <= n; i++) {
      parent.push_back(i);
      size.push_back(1);
    }
  }
  // This is known as union by size
  void union(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    if (pu == pv) return;
    if (size[pu] < size[pv]) {
      parent[pu] = pv;
      size[pv] += size[pu];
    } else {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
  int findParent(int node) {
    if (parent[node] == node) return node;
    // using dp to store and modify parent and use path compression
    // log(4 * alpha ) // proof is very long
    return parent[node] = findParent(parent[node]);
  }
};

vector<int> numIslandsII(vector<vector<int>>& positions, int m, int n) {
  // m Rows and n Cols
  DSU dsu(n * m + 1);
  int cnt = 0;
  vector<vector<int>> grid(m, vector<int>(n, 0));
  int dx[] = {-1, 1, 0, 0};
  vector<int> ans;
  int dy[] = {0, 0, -1, +1};
  for (auto& it : positions) {
    int x = it[0];
    int y = it[1];
    if (grid[x][y] == 1) {
      ans.push_back(cnt);
      continue;
    }
    grid[x][y] = 1;
    // this is a way to convert the 2d cooridinate into a single 1D coordinate
    int idx = x * m + (y + 1);
    cnt++;
    for (int dir = 0; dir < 4; dir++) {
      int newx = x + dx[dir];
      int newy = y + dx[dir];
      int newidx = newx * m + (newy + 1);
      if (dsu.findParent(idx) != dsu.findParent(newIdx)) {
        cnt--;
        dsu.union(idx, newidx);
      }
    }
    ans.push_back(cnt);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int m, n, x1, y1;
  cin >> m >> n;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1;
    arr.push_back({x1, y1});
  }
  vector<int> ans = numIslandsII(arr, m, n);
  return 0;
}

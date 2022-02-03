
class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>> &arr) {
    vector<int> adj[N + 1];
    vector<int> color(N + 1, 0);
    vector<bool> visited(N + 1, false);

    for (auto &it : arr) {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
      if (!visited[i]) {
        color[i] = 1;
        q.push(i);
        while (!q.empty()) {
          int node = q.front();
          q.pop();
          if (!visited[node]) {
            visited[node] = true;
            for (auto it : adj[node]) {
              if (color[node] == color[it]) return false;
              color[it] = color[node] == 1 ? 2 : 1;
              q.push(it);
            }
          }
        }
      }
    }
    return true;
  }
};
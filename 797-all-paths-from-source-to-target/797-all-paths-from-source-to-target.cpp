class Solution {
 public:
  vector<vector<int>> ans;
  void helper(int start, vector<int>& subset, vector<bool>& visited,
              vector<vector<int>>& graph, int target) {
    if (start == target) {
      ans.push_back(subset);
      return;
    }
    for (auto& it : graph[start]) {
      if (!visited[it]) {
        subset.push_back(it);
        visited[it] = true;
        helper(it, subset, visited, graph, target);
        // backtrack
        subset.pop_back();
        visited[it] = false;
      }
    }
    return;
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    if (n == 0) return {{}};
    vector<bool> visited(n + 1, false);
    vector<int> subset;
    subset.push_back(0);
    helper(0, subset, visited, graph, n - 1);
    return ans;
  }
};
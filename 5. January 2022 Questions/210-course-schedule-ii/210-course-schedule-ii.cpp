class Solution {
  public:
    vector < int > findOrder(int n, vector < vector < int >> & arr) {
      vector < int > indegree(n, 0);
      vector < int > ans;
      vector < int > graph[n];
      for (auto & it: arr) {
        graph[it[1]].push_back(it[0]);
        indegree[it[0]]++;
      }
      queue < int > q;
      for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
          q.push(i);

      while (!q.empty()) {

        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto & it: graph[node]) {
          indegree[it]--;
          if (indegree[it] == 0)
            q.push(it);
        }
      }
      return ans.size() == n ? ans : vector < int > ();
    }
};

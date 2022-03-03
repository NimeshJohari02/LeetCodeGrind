class DSU {
 private:
  vector<int> parent, size;

 public:
  DSU(int n) {
    for (int i = 0; i < n; i++) {
      parent.push_back(i);
      size.push_back(1);
    }
  }
  // This is known as union by size
  int findParent(int node) {
    if (parent[node] == node) return node;
    // using dp to store and modify parent and use path compression
    // log(4 * alpha ) // proof is very long
    return parent[node] = findParent(parent[node]);
  }
  void Union(int u, int v) {
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
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n+2];
        DSU dsu = DSU(n);
        for(int i=0 ; i<n; i++){
            for(int j =i+1 ; j < n ; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    dsu.Union(i , j);
                }
            }
        }
        set<int>s;
        for(int i=0 ; i< n ; i++)
            s.insert(dsu.findParent(i));
        return s.size();
    }
};
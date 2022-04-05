class DSU{
    vector<int>size , parent;
    public:
    DSU(int n){
        for(int i=0 ; i <= n ; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv ) return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>ans;
        int n = edges.size();
        DSU dsu(n);
        for(int i=0; i < n ; i++){
            if(dsu.findParent(edges[i][0]) == dsu.findParent(edges[i][1]))
            {
                ans.push_back(edges[i]);
            }
            else{
                dsu.unionBySize(edges[i][0] , edges[i][1]);
            }
        }
        return ans.back();
    }
};
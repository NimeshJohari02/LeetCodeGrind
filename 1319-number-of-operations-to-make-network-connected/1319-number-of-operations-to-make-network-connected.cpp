class DSU{
    public :
    vector<int> size , parent;
    int distinctComponents ;
    DSU(int n){
        distinctComponents = n;
        for(int i=0 ; i < n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionSize(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return ;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        distinctComponents--;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        DSU dsu(n);
        int extraEdges =0 ;
        for(auto &it : conn){
            if(dsu.findParent(it[0]) == dsu.findParent(it[1]))
                extraEdges++;
            else 
                dsu.unionSize(it[0] , it[1]);
        }
        
        if(conn.size() < n-1) return  -1 ;

         int ans = 0;
        for (int i = 0; i < n; i++)
            if (dsu.parent[i] == i)
                ans++;
        
        return ans-1;
    }
};
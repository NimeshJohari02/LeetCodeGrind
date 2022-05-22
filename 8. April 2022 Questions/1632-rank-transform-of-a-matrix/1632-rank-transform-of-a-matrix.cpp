class DSU{
    vector<int> parent , size;
    public:
    DSU(int n){
        for(int i=0 ;i <=n ;i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionSize(int u , int v ){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return ;
        if(size[pv]> size[pu])
        {
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        vector<int> rows( matrix.size()) , cols(matrix[0].size());
        map<int , vector<pair<int , int>>> mp;
        // priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        for(int i=0 ; i < matrix.size() ; i++)
            for(int j=0 ; j < matrix[0].size() ; j++)
                mp[matrix[i][j]].push_back({i , j});
        int nrow = matrix.size() ;
        int ncol = matrix[0].size();
        vector<vector<int>>ans(nrow , vector<int>(ncol , 0));        
        for(auto &it : mp){
            DSU dsu(nrow  + ncol);
            for(auto node : it.second)
                dsu.unionSize(node.first, node.second+nrow);
            unordered_map<int , int > ranks;
            for(auto &pi : it.second){
                int rn = pi.first ;
                int cn = pi.second;
                int parent = dsu.find(rn);
                ranks[parent] = max(ranks[parent] , max(rows[rn] , cols[cn])+1);
            }
            for(auto &pi : it.second){
                int root = dsu.find(pi.first), nr = pi.first , nc = pi.second , gr = ranks[root];
                ans[nr][nc] = rows[nr] = cols[nc] = gr;
            }
        }
        return ans;
    }
};
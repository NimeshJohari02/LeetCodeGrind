class DSU{
    private:
    int distinctComponents ;
    vector<int>size , parent;
    public :
    DSU(int n){
        distinctComponents = n ;
        for(int i=0 ; i <=n ; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionSize(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu== pv) return false;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
         distinctComponents--;
        return true;
    }
    bool hasOneComponent(){
        return distinctComponents==1;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();             
        vector<array<int, 3>> edges;        
        for (int i=0; i<n-1; i++) {         
            for (int j=i+1; j<n; j++) {                                                 
                int dist = abs(points[i][0]-points[j][0])
                           + abs(points[i][1]-points[j][1]); 
                edges.push_back({dist, i, j});
            }
        }
        
        // Note: Unfortunately sorting, priority_queue gives TLE.
        make_heap(edges.begin(), edges.end(), greater<>()); 
        DSU dsu(n);   
        int cost = 0;     
        while(!edges.empty() && !dsu.hasOneComponent()) {
            pop_heap(edges.begin(), edges.end(), greater<>()); 
            auto edge = edges.back(); 
            int p1 = edge[1];  
            int p2 = edge[2];  
            if (dsu.unionSize(p1, p2)) {  
                cost += edge[0];  
            }
            edges.pop_back();  
        }
        return cost;  
    }
};



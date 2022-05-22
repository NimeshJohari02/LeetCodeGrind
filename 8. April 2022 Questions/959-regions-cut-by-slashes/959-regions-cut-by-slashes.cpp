class DSU{
    vector<int> parent , size;
    public :
    int count ;
    DSU(int n ){
        count =1 ;
        for(int i=0 ; i <= n ; i++){
            size.push_back(1);
            parent.push_back(i);
        }
    }
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionSize(int u , int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) {count++ ; return ;} 
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size() ;
        int dots = n+1;
        DSU dsu(dots * dots);
        int count =1 ;
        // Connect the DOTS;
        for(int i =0 ; i < dots ; i++)
            for(int j=0 ; j < dots;j++)
                if(i==0 || j==0 || i == dots-1 || j==dots-1)
                    if((i * dots)+j !=0)
                        dsu.unionSize(0 , i*dots + j);
        for(int i=0 ; i < n ; i++){
            for(int j=0 ; j < grid[i].size() ; j++){
             if(grid[i][j] == '/'){
                  int cell1 = i*dots +  j+1;
                  int cell2 = (i+1)*dots + j;
                 dsu.unionSize(cell1, cell2);
             }
             else if(grid[i][j] =='\\'){
                int cell1 = i*dots +  j;
                  int cell2 = (i+1)*dots + (j+1);
                 dsu.unionSize(cell1, cell2);   
             }
            }
        }
    return dsu.count;
    }
};
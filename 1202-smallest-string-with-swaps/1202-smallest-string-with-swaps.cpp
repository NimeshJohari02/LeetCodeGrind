class DSU{
    vector<int>parent;
    vector<int>size;
    public :
    DSU(int n ){
        for(int i=0 ; i<n ; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find(int u ){
        if(u == parent[u]) return u;
        return parent[u]  = find(parent[u]);
    }
    void unionSize(int u , int v ){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return ;
        if(size[pv] > size[pu]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //sort(pairs.begin() , pairs.end());
        // agar uss element ka parent == element itself then no swap else we need to swap /
        DSU d(s.size()) ;
        for(auto &it : pairs){
            if(d.find(it[0]) != d.find(it[1])) d.unionSize(it[0] , it[1]);
        }
        unordered_map<int , vector<int>> mpp;
        for(int i=0 ; i < s.size() ; i++)
            mpp[d.find(i)].push_back(i);
        for(auto &x : mpp){
            string str  = "" ;
            int j = 0 ;
            for(auto &it : x.second) str+=s[it];
            sort(str.begin(), str.end());
            for(auto &i : x.second) s[i] = str[j++];
        }
        return s;
    }
};
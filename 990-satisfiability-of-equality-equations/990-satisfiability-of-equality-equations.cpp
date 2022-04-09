
class DSU{
    public :
    vector<int>parent;
    DSU(int n ){
        for(int i=0 ; i <= n ; i++)
            parent.push_back(i);
    }
    int find(int node){
        if(node != parent[node]) parent[node] = find(parent[node]);
        return parent[node];
    }
    
};
class Solution {
public:
    int getInt(char ch){
        return (int) ch - 'a';
    }
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for (string e : equations)
            if (e[1] == '=')
                dsu.parent[dsu.find(getInt(e[0]))] = dsu.find(getInt(e[3]));
        for (string e : equations)
            if (e[1] == '!' && dsu.find(getInt(e[0])) == dsu.find(getInt(e[3])))
                return false;
        return true;
    }
};
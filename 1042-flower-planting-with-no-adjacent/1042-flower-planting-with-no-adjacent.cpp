// Coloring Problem 
/*
1 -> Fl1 
2 -> FL2 
3 -> FL3 
4 -> FL4 
*/
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>adj[n];
        for(auto &it : paths){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int>ans(n , 0);
        for(int i=0 ; i < n ; i++){
            vector<int>color(5 , 0);
            for(auto &j : adj[i])
                color[ans[j]] = 1;
            for(int cols = 4 ; cols >0 ; cols--){
                if(!color[cols])
                    ans[i] = cols;
            }
            }
        return ans;
    }
};
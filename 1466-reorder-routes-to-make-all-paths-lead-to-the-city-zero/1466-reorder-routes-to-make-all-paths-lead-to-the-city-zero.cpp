class Solution {
public:
    int dfs(int node , vector<int>adj[] , vector<bool>&visited){
        visited[node] =true;
        int ans =0;
        for(auto &it : adj[node]){
            if(!visited[abs(it)]){
                ans += dfs(abs(it) , adj , visited) + (it > 0 ? 1 : 0);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<bool>visited(n , false);
        vector<int> adj[n];
        for(int i=0 ; i < conn.size() ; i++){
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(-conn[i][0]);
        }
        return dfs(0 , adj , visited );
    }
};
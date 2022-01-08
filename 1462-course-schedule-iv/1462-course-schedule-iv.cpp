class Solution {
private:
    void BFS(vector<int>adj[] , vector<vector<bool>>&reachable , vector<vector<bool>>&visited, int node , queue<int>&q){    
            q.push(node);
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(auto &it: adj[front]){
                    if(visited[node][it])continue;
                        q.push(it);
                        reachable[node][it]=true;
                        visited[node][it]=true;
                }
            }
        return ;
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& arr) {
        vector<int>adj[n];
        for(auto& it : pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<bool>>reachable(n , vector<bool>(n , false));
        vector<vector<bool>>visited(n , vector<bool>(n , false));
        queue<int>q ;
        for(int i=0 ; i < n ; i++){
            BFS(adj , reachable ,visited , i, q );
        }
        vector<bool>ans;
        for(auto&it: arr)
            ans.push_back(reachable[it[1]][it[0]]);
        return ans;
    }
};
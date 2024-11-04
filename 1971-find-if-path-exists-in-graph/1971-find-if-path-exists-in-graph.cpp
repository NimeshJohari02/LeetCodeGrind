class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>visited(n , false);
        vector<int>adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q ;
        q.push(source);
        visited[source] = true ;
        while(!q.empty()){
            auto node = q.front() ;
            q.pop();
            for(auto adjNode : adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = true ;
                    q.push(adjNode);
                }
            }
        }
        return visited[destination];
    }
};
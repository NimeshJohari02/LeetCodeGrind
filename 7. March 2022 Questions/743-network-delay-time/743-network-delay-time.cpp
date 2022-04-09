class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int , int >> adj[n+1];
        for(auto &it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        // Cost , Node
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>> > q;
        // Start the bfs from the Node k ;
        q.push({0 , k});
         vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            int u = node.second;
            for(auto &it : adj[node.second]){
                int v = it.first;
                int w = it.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=1 ; i <= n ;i++)
            ans = max(ans , dist[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};

// BELLMAN FORD FROM THE DISCUSSION SECITON THIS GIVES TLE !!!!!!
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        // We perform the relaxation of edges N times 
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // reverse djikstra with normal pq;
        // dist , node  -> pair
        vector<double>ans(n ,0.0);
        vector<bool> visited(n, false);
        priority_queue<pair<double,int>>pq;
        vector<pair<int,double>>adj[n];
        for(int i= 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        ans[start]=1.0;
        pq.push({1.0 , start });
        while(!pq.empty()){
            pair<double,int> pd = pq.top();
            pq.pop();
            int node = pd.second;
            double prob = pd.first;
            if(!visited[node]){
                visited[node] = true;
                for(auto&it : adj[node]){
                    if(ans[it.first] < it.second * prob){
                        ans[it.first ] = it.second * prob ;
                        pq.push({ans[it.first] , it.first});
                    }
                }
            }
        }
        return ans[end];
    }
};
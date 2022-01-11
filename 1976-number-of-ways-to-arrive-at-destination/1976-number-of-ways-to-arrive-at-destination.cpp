class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long >distance(n , 1e18);
        vector<long long>ways(n , 0 );
        vector<pair<long long,long long>>adj[n];
        for(auto&it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        ways[0]=1;
        distance[0]=0;
        long long mod = 1e9+7;
        priority_queue<pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]){
                long long wt = it.second;
                long long adjNode = it.first;
                if(wt + dist < distance[adjNode] ){
                    distance[adjNode] = wt+dist;
                    ways[adjNode] = ways[node];
                    pq.push({distance[adjNode] , adjNode});
                }
                else if(wt + dist == distance[adjNode])
                    ways[adjNode] = (ways[adjNode] + ways[node] )% mod;   
            }
        }
        return ways[n-1];
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int , int>>adj[n];
        for(int i=0 ; i < flights.size() ; i++){
            adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }
        // Standard Djikstra fails obviously as the distance/cost will not be P0 in the queue 
        queue<vector<int>>q;
        vector<int>dist(n , 1e9);
        // Source and distance is given. 
        dist[src] = 0 ;
        q.push({0 , src , 0});
        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            int currentStops = vec[0];
            int currentNode = vec[1];
            int currentPrice = vec[2];
            if(currentStops > k )continue ;
            if(currentNode == dst && currentStops <= k){
                dist[dst] = min(dist[dst] , currentPrice);
            }
            for(auto &it : adj[currentNode]){
                auto [nextNode , priceToPay] = it ;
                if(currentPrice + priceToPay < dist[nextNode] && currentStops <= k){
                    dist[nextNode] = currentPrice + priceToPay;
                    q.push({currentStops+1 , nextNode , dist[nextNode]});
                }
            }
            
            
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() , i=0;
        vector<int> adj[n] , indeg(n , 0 ) , ans;
     for(auto& g : graph) {
		for(auto& it : g) {
			adj[it].push_back(i);
			indeg[i]++;
		}
		i++;
     }
        queue<int > q;
        for(int i=0 ; i < n ; i++)
            if(indeg[i] ==0 ) q.push(i);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto &it : adj[node]){
            if(--indeg[it] ==0 ) q.push(it);
        }
    }
        sort(ans.begin() , ans.end());
        return ans ;
    }
};
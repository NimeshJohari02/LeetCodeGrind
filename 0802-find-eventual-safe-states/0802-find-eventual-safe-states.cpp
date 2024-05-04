class Solution {
public:
    bool dfsCycleCheck(int node , vector<int>adj[] , vector<bool>&visited , vector<bool>&pathVisited , vector<bool>&check){
        visited[node] = true;
        pathVisited[node]= true;
        check[node]=false;
        for(auto &it : adj[node]){
            if(!visited[it]){
                if(dfsCycleCheck(it , adj , visited , pathVisited , check) == true)return true;
            }
            // Visited Already
            else if(pathVisited[it]==true)
                return true ;
        }
        pathVisited[node] = false;
        check[node]= true;
        return false ;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
    for(int i=0 ; i < graph.size() ;i++){
        for(int j =0 ; j < graph[i].size() ;j++){
            cout<<"pushing "<<graph[i][j] <<" in the list of" <<i <<"\n";
            adj[i].push_back(graph[i][j]);
        }
    }
        vector<int>ans;
        vector<bool>visited(n , false);
        vector<bool>pathVisited(n , false);
        vector<bool>checker(n , false);
        for(int i=0 ; i < n ; i++){
            if(!visited[i]){
                dfsCycleCheck(i , adj , visited , pathVisited , checker);
            }
        }
        for(int i=0 ; i < n ; i++)
            if(checker[i])ans.push_back(i);
        return ans; 
    }
};
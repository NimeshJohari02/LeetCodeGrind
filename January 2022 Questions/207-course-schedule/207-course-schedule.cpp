class Solution {
    private:
    bool dfsCycle(int node , vector<int>&visited ,vector<int>&pathVisited , vector<int>graph[]){
        visited[node]=1;
        pathVisited[node]=1;
        for(auto &it : graph[node]){
            if(visited[it]==0){
                if(dfsCycle(it , visited , pathVisited , graph)) return true;
            }
            else if(pathVisited[it]==1)
                return true;
        }
        pathVisited[node]= 0;
        return false;
        
    }
    
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int>graph[n];
        vector<int>visited(n , 0 ) , pathVisited(n , 0 );
        for(auto &it : arr){
            graph[it[1]].push_back(it[0]);
        }
        for(int i=0 ; i <n ; i++){
            if(!visited[i]){
                if(dfsCycle(i , visited , pathVisited , graph)){
                    return false;
                }
            }
        }
        return true;  
    }
};
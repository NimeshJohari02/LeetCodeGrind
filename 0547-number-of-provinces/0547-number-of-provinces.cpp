class Solution {
public:
    void DFS(vector<vector<int>>&adj , int startNode , vector<bool>&visited){
        visited[startNode]= true ;
        for(int i=0 ; i < adj[startNode].size() ;i++){
                if(!visited[i] && adj[startNode][i]==1)
                    DFS(adj , i , visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), numProvince = 0 ;
        vector<bool>visited(n, false);
        for(int i=0 ; i< n ; i++){
            if(!visited[i]){
                DFS(isConnected , i , visited);
                numProvince++;
            }
        }
        return numProvince;
    }
};
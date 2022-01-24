class Solution {
public:
    // 0 is white / nocolor 
    // 1 is red 
    // 2 is blue as usual
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        int n = graph.size() ;
        vector<bool>visited(n+1 , false);
        vector<int>color(n+1 , 0);
        for(int i=0 ; i < n ; i++){
            if(!visited[i]){
                color[i]= 1;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    if(!visited[node]){
                        visited[node] =true;
                        for(auto &it : graph[node]){
                            if(color[it]==color[node])return false;
                            color[it] = color[node]==1 ? 2:1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
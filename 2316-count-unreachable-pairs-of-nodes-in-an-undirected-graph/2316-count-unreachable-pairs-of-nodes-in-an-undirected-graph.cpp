/*
Method 1 BFS Gives TLE;
class Solution {
public:
    int bfs(int node , vector<int>adj[] , int n){
        vector<bool>visited(n , false);
        visited[node] = true;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto &iit : adj[it]){
                if(!visited[iit]){
                    visited[iit] = true;
                    q.push(iit);
                }
            }
        }
        int ans = 0 ;
        for(int i=0 ; i < n ; i++){
            ans += visited[i]==false;
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans = 0 ;
        for(int i=0 ;i < n ; i++)
            ans += bfs(i , adj , n);
        return ans/2;
    }
};


*/


class Solution {
public:
    void dfs(int node , long long& cnt , vector<int>adj[] ,  vector<bool>&visited){
        visited[node] = true;
        cnt++;
        for(auto &it : adj[node])
            if(!visited[it])
                dfs(it , cnt , adj , visited);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        // I can take ALl pairs in graph , then if we can reach by dfs subtract them ;
        long long ans = ((long long)n * (long long)(n-1) / 2);
        vector<int>adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]);
        };
        vector<bool>visited(n , false);
        for(int i=0 ; i < n ; i++)
            if(!visited[i]){
                long long  cnt = 0 ;
                dfs(i , cnt , adj , visited);
                ans -= (cnt*(cnt-1))/2;
            }
    return ans;
    }
};
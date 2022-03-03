class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
    //     if(arr.size() ==1 ){
    //         return 0;
    //     }
    //     map<int,vector<int>>mp;
    //     int n = arr.size();
    //     for(int i=0 ; i < n ; i++){
    //         mp[arr[i]].push_back(i);
    //     }
    //     set<int>adj[n+1];
    //     for(int i=0 ; i < n ; i++){
    //         if(i+1<n)
    //         adj[i].insert(i+1);
    //         if(i-1>=0)
    //         adj[i].insert(i-1);
    //         for(auto&it : mp[arr[i]]){
    //             if(it==i)continue;
    //             adj[i].insert(it);
    //         }
    //     }
    // int start =0;
    // int end = arr.size()-1;
    // vector<bool> visited(n + 1, false);
    // visited[start] = true;
    // queue<pair<int, int>> q;
    // q.push({start, 0});
    // while (!q.empty())
    // {
    //     int node = q.front().first;
    //     int steps = q.front().second;
    //     if (node == end)
    //         return steps;
    //     q.pop();
    //     for(auto &it : adj[node]){
    //         if(!visited[it]){
    //         visited[it] = true;
    //         q.push({it , steps+1});
    //     }
    //     }
    // }
    // return -1;
     int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        vector<bool> visited(n); visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
    }
};
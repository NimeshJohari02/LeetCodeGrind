class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>adj[n];
        for(int i=0 ; i < n ; i++){
            for(auto &it : rooms[i]){
                adj[i].push_back(it);
            }
        }
    
        for(int i=0 ;  i< n ; i++){
            for(auto &it : adj[i]){
                cout<<it<<"    ";
            }
            cout<<"\n";
        }
        vector<bool>visited(n , false);
        queue<int>q;
        visited[0] = true;
        q.push(0);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto &it : adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }

        for(int i=0 ; i < n ;i++)
            if(visited[i] == false) return false;
        return true;
    }
};
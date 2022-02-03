// class Solution {
// public:
//     bool canIntersect(pair<int,int>&src , pair<int,int>&desn , int srcR , int desnR){
//         int distance =  sqrt(pow((desn.second - desn.first),2)+ pow((desn.second - desn.first) , 2) );
//         return distance <= (srcR+desnR);
//     }
//     int BFS(map<pair<int,int> , vector<pair<int , int>>> &mp , pair<int,int>src){
//         queue<pair<int,int>>q;
//         q.push(src);
//         int cnt =1;
//         map<pair<int,int>,bool>visited;
//         for(auto &it :mp){
//             visited[it.first]=false;
//         }
//         while(!q.empty()){
//             pair<int, int>node = q.front();
//             q.pop();
//             if(!visited[node]){
//                 for(auto &it : mp[node]){
//                     visited[it]=true;
//                     q.push(it);
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
//     int maximumDetonation(vector<vector<int>>& bombs) {
//         // general graph is vi adj here we make map<pair<int,int> , pair<int,int>>
//         map<pair<int,int> , vector<pair<int , int>>>mp;
//         for(int i=0 ; i < bombs.size() ; i++){
//             for(int j =i+1 ; j < bombs.size() ; j++){
//                 pair<int,int>src = {bombs[i][0] , bombs[i][1]};
//                 int srcRadius = bombs[i][2];
//                 pair<int,int>desn = {bombs[j][0] , bombs[j][1]};
//                 int desnRadius = bombs[j][2];
//                 if(canIntersect(src , desn  , srcRadius , desnRadius)){
//                     mp[src].push_back(desn);
//                     mp[desn].push_back(src);
//                 }
//             }
//         }
//         int ans = INT_MIN;
//         for(auto&it : mp){
//             ans = max (ans , BFS(mp, it.first));
//         }
//         return ans;
//     }
// };


class Solution {
public:
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        ios::sync_with_stdio(false); cin.tie(NULL);
		
        const int n = bombs.size();
		
        vector<vector<int>>v(n);
        
        for(int i = 0; i < n; i++) {
            long long r = (long long)bombs[i][2] * bombs[i][2];
            for(int j = 0; j < n; j++) {
                if(i != j){
                    if((long long)((long long)bombs[i][0]-bombs[j][0]) * ((long long)bombs[i][0]-bombs[j][0])+(long long)(bombs[i][1]-bombs[j][1]) * ((long long)bombs[i][1]-bombs[j][1]) <= r){
                       v[i].push_back(j);
                    }
                }
            }
        }
        
        int ans = 1;
        // try each bomb and choose that which contributes maximum detonation.
        for(int i = 0; i < n; i++){
            vector<bool>vis(n, 0);
            int mx = 0;
            
			queue<int>q;
            q.push(i);
			
            while(!q.empty()) {
                int s = q.size();
                for(int i = 0; i < s; i++) {
                    int x = q.front();
                    q.pop();
                    vis[x] = 1;
                    mx++;
                    for(auto p : v[x]) {
                        if(!vis[p]) {
                            q.push(p);
                            vis[p] = 1;
                        }
                    }
                }
            }
            ans = max(ans, mx);
        }
        
        return ans;
    }
};
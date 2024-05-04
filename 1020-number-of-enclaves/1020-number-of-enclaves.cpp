class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m =grid[0].size();
        vector<vector<bool>>visited(n , vector<bool>(m , false));
        //Algo 
        //Maintain Count of all 1's 
        // If boundary 1 then subtract that from ans and for all subsequent nodes visited keep var as connectedNodes ;
        // ans = countOnes-connectedNode ;
        int countOnes = 0 , connectedNodes = 0;
        queue<pair<int ,int>>q;
        for(int i=0 ; i < n ; i++){
            for(int j =0 ; j<m ;j++){
                if(grid[i][j]==1)countOnes++ ;
                if(grid[i][j]==1 && (i==0 || j ==0 || i==n-1 || j==m-1)){
                    visited[i][j] = true;
                    q.push({i , j});
                    connectedNodes++;
                }
            }
        }
        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();
            int dx[]={1 , -1 , 0 , 0};
            int dy[]={0 , 0 , 1 , -1};
            for(int k=0 ; k < 4 ; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >=0 && nx < n && ny >=0 && ny < m && !visited[nx][ny] && grid[nx][ny]==1){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                    connectedNodes++;
                }
            }
        }
        return countOnes-connectedNodes;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Distance to the nearest 0 
        queue<pair<int , pair<int , int>>> q;
        int m = mat.size() ;
        int n = m ? mat[0].size() : 0 ;
        vector<vector<bool>>visited(m , vector<bool>(n , false));
        vector<vector<int>>distanceMatrix(m , vector<int>(n,INT_MAX));
        // Creating Initial Config ;
        for(int i=0 ;i < m ; i++){
            for(int j=0 ; j < n ;j++){
                if(mat[i][j]==0){
                    distanceMatrix[i][j]= 0;
                    visited[i][j]= true;
                    q.push({0 , {i , j}});
                }
            }
        }
        int dx[]={1 , -1 , 0 ,0};
        int dy[]={0 , 0 , 1 , -1};
        while(!q.empty()){
            auto distanceCoordinatePair = q.front();
            q.pop();
            auto [distance , xyPair] = distanceCoordinatePair;
            auto [x , y] = xyPair;
            for(int k =0 ; k < 4;k++){
                int deltaX = x + dx[k];
                int deltaY = y + dy[k];
                if(deltaY < n && deltaX < m && deltaY >=0 && deltaX>=0 && mat[deltaX][deltaY]!=0 && !visited[deltaX][deltaY]){
                    visited[deltaX][deltaY] = true;
                    distanceMatrix[deltaX][deltaY] = min( distanceMatrix[deltaX][deltaY] , distance+1);
                    q.push({distance+1 , {deltaX , deltaY}});
                }
            }
        }
        return distanceMatrix;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size(); 
     // Minimize the maximum Absolute Difference . 
    // Generally this statement is for binary search in case in a 1d 
    // Since this is a 2d grid we can use djikstra
        vector<vector<int>>minCostGrid(n , vector<int>(m , 1e9));
        // priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq ;
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq;
        // Difference  x Coord , y Coord
        pq.push({0 , {0 , 0}});
        minCostGrid[0][0]=0 ;
        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();
            int currentDifference = vec.first;
            int x = vec.second.first;
            int y = vec.second.second;
            if(x==n-1 && y==m-1 )return currentDifference;
            int dx[] = {0 , 0 , 1 , -1};
            int dy[] = {1 ,-1 , 0 , 0 };
            for(int k =0 ; k < 4 ; k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx < n && nx >= 0 && ny < m && ny >= 0){
                    int newEffort = max(currentDifference , abs(heights[nx][ny] - heights[x][y]));
                    if(newEffort < minCostGrid[nx][ny] ){
                        minCostGrid[nx][ny]= newEffort ;
                        pq.push({newEffort ,{nx , ny}});
                    }
                }
            }   
        }
        return 0;
    }
};
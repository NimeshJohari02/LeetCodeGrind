class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int r = grid.size() , c = grid[0].size(),totalOranges =0 , mins =0 , rottenOrangeCount=0;
        queue<pair<int,int>>q;
        for(int i =0 ; i< r ; i++){
            for(int j =0 ; j<c; j++){
                if(grid[i][j]!=0){
                    totalOranges++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        // xdir[i],ydir[i] denote up right left and down indexs
        vector<int>xdir={0,0,1,-1};
        vector<int>ydir={1,-1,0,0};
        while(!q.empty()){
            int k = q.size();
            rottenOrangeCount+=k;
                while(k--){
                    pair<int,int>rotten = q.front();
                    q.pop();
                    for(int i=0 ; i < 4 ; i++){
                        int mx = rotten.first+xdir[i];
                        int my = rotten.second+ydir[i];
                        if(mx <0 ||  my <0 || mx >=r || my >=c || grid[mx][my]!=1){
                            continue;
                        }
                        grid[mx][my]=2;
                        q.push({mx,my});
                    }   
                }
            if(!q.empty()){
                mins++;
            }
        }
        
        return totalOranges==rottenOrangeCount?mins:-1;
    }
};
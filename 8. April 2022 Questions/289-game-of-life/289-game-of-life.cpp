class Solution {
public:
    int getaliveCount(vector<vector<int>>&g , int i , int j){
        int ans =0;
        int m = g.size() ;
        int n = g[0].size();
        ans+=(j-1 >=0 ? g[i][j-1]: 0 ) +
                    (j+1 <n ? g[i][j+1] : 0) + 
                    (i+1 < m && j+1 < n ? g[i+1][j+1] : 0)+
                    (i+1 < m && j-1 >=0 ? g[i+1][j-1] : 0)+       
                    (i+1 < m  ? g[i+1][j] : 0 )+
                    (i-1 >=0 ? g[i-1][j] : 0)+ 
                    (i-1 >=0 && j-1>=0  ? g[i-1][j-1] : 0)+
                    (i-1 >=0 && j+1 < n ? g[i-1][j+1] : 0);
    return ans;
    }
    void gameOfLife(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> temp= g;
        for(int i=0 ; i < m ; i++){
            for(int j =0 ; j < n ; j++){
                int alive = getaliveCount(temp , i , j);
                cout<<"Alive For "<<i<<"  "<<j<<" "<< alive<<"\n";
                 if(g[i][j]==1 ) {
                    if(alive < 2 || alive > 3) g[i][j] = 0;
                } else {
                    g[i][j] = alive == 3 ? 1 : 0;
                }
            }
        }
    }
};
class Solution {
public:
    int mod = (int)1e9+7;
    int maxi =0 ;
    int rec(int x , int y , int m , int row , int col , vector<vector<vector<int>>>&dp ){
        if(x < 0 || y < 0 || x>=row || y>=col) return 1 ;
        if(m == maxi ) return 0 ;
        if(dp[x][y][m] != -1) return dp[x][y][m] % mod;
        long long int temp = 0 ;
        int dx[]={1 ,-1 ,0 , 0};
        int dy[]={0 , 0 , 1 , -1};
        for(int i=0 ; i < 4 ; i++)
            temp += rec(x+dx[i] , y + dy[i] ,m+1 , row , col , dp ) % mod;
        return dp[x][y][m] = temp % mod;
    }
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        maxi = maxMove;
        vector<vector<vector<int>>>dp(m , vector<vector<int>>(n , vector<int>(maxMove , -1)));
        return rec(sr , sc  ,0 , m , n , dp );
    }
};
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>>dp(row+1 , vector<int>(cols+1 , INT_MAX));
        dp[row][cols-1]=1;
        dp[row-1][cols]=1;
        // Direction Bottom right is smallest problem with going top right as ans;
        for(int i=row-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                int val = min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                // now if it is a power up cell then you only need 1 as minimum hp to move thus 
                dp[i][j]= val<=0 ? 1 : val;
            }
        }
        return dp[0][0];
    }
};


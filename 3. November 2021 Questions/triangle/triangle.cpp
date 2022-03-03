class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    vector<int>dp(triangle.back());
    int n = triangle.size();
        for(int l = n-2 ; l >=0 ; l--){
            for(int i =0 ; i <=l ; i++){
                dp[i]= min(dp[i],dp[i+1])+triangle[l][i];
            }
        }
        return dp[0];
    } 
};
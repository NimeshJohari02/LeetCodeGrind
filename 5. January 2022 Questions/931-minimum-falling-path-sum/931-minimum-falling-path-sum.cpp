class Solution {
public:
    int tabulation(vector<vector<int>>&matrix){
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0 ; i<matrix[0].size();i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1 ; i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int top = dp[i-1][j];
                int topLeft = j>=1?dp[i-1][j-1]:INT_MAX;
                int topRight = j+1<matrix[i].size()?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min(min(top,topLeft),topRight);
            }
        }
        int ans =INT_MAX;
        for(auto it : dp.back()){
            ans=min(it,ans);
        }
    return ans;
    }
    int spaceOptimized(vector<vector<int>>&arr){
        int n = arr.size();
        vector<int>prev(n , 0) , currRow(n , 0 );
        for(int i=0 ; i < n ; i++)
            prev[i] = arr[0][i];
        
        for(int i =1 ; i< n ; i++){
            for(int j=0 ; j <n ; j++){
                int top = arr[i][j]+prev[j];
                int topLeft = arr[i][j]+ j>=1 ? prev[j-1] :INT_MAX;
                int topRight = arr[i][j]+ (j+1)<n?prev[j+1] :INT_MAX;
                currRow[j] =  min(min(top ,topLeft),topRight);
            }
            prev = currRow;
        }
        int ans =INT_MAX;
        for(auto&it:prev){ 
            cout<<it<<" ";
            ans = min(ans , it);}
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return tabulation(matrix);
    }
};
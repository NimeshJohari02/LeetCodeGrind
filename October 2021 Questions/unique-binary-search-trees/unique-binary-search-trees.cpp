class Solution {
public:
    // Number Of Unique Trees Always Equal To Catalan Number . Thus calculate catalan Number Normal Recursive soln might give tle
    // thus use memoization
    int dp[20];
    int findCatalanNumber(int n){
     if(dp[n]!=-1){
         return dp[n];
     }   
        if(n<=1){
            return dp[n]=1;
        }
        long long int res =0;
         for (int i = 0; i < n; i++){
         res += findCatalanNumber(i)* findCatalanNumber(n - i - 1);
         }
        return dp[n]= res;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
    return findCatalanNumber(n);
    }
};
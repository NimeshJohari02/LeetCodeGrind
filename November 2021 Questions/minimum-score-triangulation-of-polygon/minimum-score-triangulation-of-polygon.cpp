class Solution {
public:
    int dp[51][51];
    int MCM(vector<int>&vals , int i , int j ){
        int res = 0;
        if(dp[i][j]!=0){
            return dp[i][j];
        }
         for(int k = i+1 ; k<j ; k++) {
               res = min( res==0?INT_MAX:res ,MCM(vals , i , k)+vals[i]*vals[j]*vals[k]+ MCM(vals , k , j ));
           }
        return dp[i][j]=res; 
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,0,sizeof(dp));
     return MCM(values, 0 , values.size()-1)   ;
    }
};
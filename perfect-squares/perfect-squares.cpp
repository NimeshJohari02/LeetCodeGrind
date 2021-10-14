class Solution {
public:
    int dp[10001];
    int numSquares(int n ){
        dp[0]=0;
        vector<int>sq;
        dp[1]=1;
        sq.push_back(1);
        for(int i=2;i<=n;i++){
            
            if(ceil(sqrt(i))==floor(sqrt(i))){
                dp[i]=1;
                sq.push_back(i);
            }
            else{
                // int prevSquare= pow(floor(sqrt(i)),2);
                int currMin = INT_MAX;
                for(int j =0;j<sq.size();j++){
                    int candidate = dp[i-sq[j]]+dp[sq[j]];
                    currMin= min(currMin,candidate);
                }
                dp[i]=currMin;
            }
        }
     return dp[n];   
    }
};
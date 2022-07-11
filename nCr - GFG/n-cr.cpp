// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int MOD = (int) 1e9+7;
    int nCr(int n, int r){
        int dp[n+1][r+1]; 
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= i and j <= r; j++){
                if (j == 0 or i == j)
                    dp[i][j] = 1;  
                else 
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD; 
            }
        }
        return dp[n][r]; 
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
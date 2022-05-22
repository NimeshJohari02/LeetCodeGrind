// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(int i , int j , int arr[] ,vector<vector<int>>&dp){
        if(i==j) return dp[i][j]=0;
        int ans = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k <= j-1 ; k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) + rec(i ,k , arr , dp) + rec(k+1 , j , arr , dp);
            ans = min(ans , steps);
        }
        return dp[i][j]=ans ;
    }
    int tabulation(int n , int arr[]){
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
        for(int i=n-1 ; i>=1 ; i--){
            for(int j = i+1 ; j <=n-1 ; j++){
                int ans = INT_MAX;
             for(int k = i ; k <= j-1 ; k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
            ans = min(ans , steps);
            }
            dp[i][j] = ans;
            }
        }
        return dp[1][n-1];
    }
    int matrixMultiplication(int n, int arr[])
    {
        // vector<vector<int>>dp( n+1 , vector<int>(n+1 , -1));
        // return rec(1 , n-1 , arr ,dp);
        return tabulation(n , arr);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
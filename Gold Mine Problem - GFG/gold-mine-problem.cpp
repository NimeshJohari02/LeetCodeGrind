// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> arr)
    {
        vector<vector<int>>dp( n , vector<int> (m , 0));
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++)
                if (j == 0)
                    dp[i][j] = arr[i][j]; 
                else{
                    int temp = INT_MIN ;
                    if (i - 1 >= 0 and j -1 >= 0)
                        temp = max(temp, dp[i-1][j-1]); 
                    if (j - 1 >= 0)
                        temp = max(temp, dp[i][j-1]); 
                    if (i + 1 < n and j - 1 >= 0)
                        temp = max(temp, dp[i+1][j-1]); 
                    dp[i][j] = temp + arr[i][j];
                }
        }
        int ans = INT_MIN;
        // for(int i=0 ; i < n ; i++)
        // {
        //     for(int j =0 ; j < m ; j++){
        //         cout<<dp[i][j]<<"  ";
        //     }
        //     cout<<"\n";
        // }
        // return ans;
        // return *max_element(dp.back().begin() , dp.back().end
             for(int i = 0; i < n; i++)
            ans = max(ans, dp[i][m-1]); 
        return ans; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
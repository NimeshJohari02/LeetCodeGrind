// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int recursive(int idx , int arr[] , int amount  ){
        if(idx ==0 ) {
            return (amount % arr[0] == 0) ;
        }
            long long int notTake = recursive(idx-1 , arr , amount );
            long long int take  = 0 ;
            if(amount >= arr[idx])
            take = recursive(idx , arr , amount-arr[idx]  );
            return take + notTake ;
    }
    long long int  tabulation(int arr[] , int m , int amt){
        vector<vector<long long int >>dp(m , vector<long long int >(amt+1 , 0));
        for(int T=0 ; T <= amt ; T++)
        dp[0][T] = T % arr[0] ==0 ;
        for(int idx =1 ; idx<=m-1 ; idx++){
            for(int T =0 ; T<= amt ; T++){
                long long int nt = dp[idx-1][T];
                long long int t = 0 ;
                if(T >= arr[idx])
                t = dp[idx][T-arr[idx]];
                dp[idx][T] = t+nt;
            }
        }
        return dp[m-1][amt];
    }
    
    
    long long int count(int S[], int m, int n) {
        // return recursive(m-1 , S , n );
        return tabulation(S , m , n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
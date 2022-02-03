// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sumOfArr = 0;
	    for(int i=0 ; i < n ; i++)
	    sumOfArr+=arr[i];
	    vector<vector<bool>>dp(n , vector<bool>(sumOfArr+1 , 0));
	    for(int i=0 ; i < n ; i++)
	    dp[i][0]=true;
	    dp[0][arr[0]] = true;
	    for(int i = 1 ; i <= n-1 ; i++){
	        for(int target =1 ; target <= sumOfArr; target++){
	            bool nottake = dp[i-1][target];
	            bool take = false;
	            if(target >= arr[i]){
	                take = dp[i-1][target - arr[i]];
	            }
	            dp[i][target] = take | nottake;
	        }
	    }
	  int mindif = INT_MAX;
	  for(int i=0 ; i <= sumOfArr/2 ; i++){
	      if(dp[n-1][i]){
	      mindif= min(abs(i - (sumOfArr-i)), mindif);
	  }
	  }
	  return mindif;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
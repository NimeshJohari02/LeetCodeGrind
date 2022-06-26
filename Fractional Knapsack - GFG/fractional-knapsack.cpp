// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{

    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(const Item i1 , const Item i2){
        return (double)i1.value/(double)i1.weight > (double)i2.value/(double)i2.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        sort(arr , arr+ n , cmp);
        for(int i=0 ; i < n ; i++)
        {
            if(W==0) break;
            Item maxi = arr[i];
            if(W > maxi.weight)
            ans += maxi.value  , W-=maxi.weight;
            else {
                ans += double(maxi.value) / (double) maxi.weight * W;
                W=0;
            }
        }
    return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
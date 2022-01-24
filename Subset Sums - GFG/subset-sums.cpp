// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    private : 
    vector<int>ans;
    void generateSubsets(int idx , vector<int>&arr , vector<int>&subset ,int currSum)
    {
        if(idx == arr.size()){
        ans.push_back(currSum);
        return ;
    }
    subset.push_back(arr[idx]);
    generateSubsets(idx+1,arr , subset , currSum + arr[idx]);
    subset.pop_back();
    generateSubsets(idx+1 , arr , subset , currSum);
}
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Writ  Code here
        vector<int>subset;
        generateSubsets(0 , arr ,subset , 0 );
        sort(ans.begin() , ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
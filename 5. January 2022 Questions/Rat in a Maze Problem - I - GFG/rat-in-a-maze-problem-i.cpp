// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i , int j , vector<vector<int>>& m , int n , vector<string>&ans , string path , vector<vector<int>>&visited){
        // int dx[]={0,-1 ,1  , 0};
        // int dy[]={1,0 , 0   , -1};
        if(i== n-1 && j==n-1)
        {
            ans.push_back(path);
            return ;
        }
        if(i+1 < n && !visited[i+1][j] && m[i+1][j]==1){
            visited[i][j] =1;
            solve(i+1 , j , m , n , ans, path+'D' , visited);
            visited[i][j]=0;
        }
        if(j-1 >=0 && !visited[i][j-1] && m[i][j-1] ==1)
        {
            visited[i][j]=1;
            solve(i , j-1 ,m ,n ,ans ,  path+'L'  , visited);
            visited[i][j]=0;
        }
        if(j+1 <n && !visited[i][j+1] && m[i][j+1]==1){
            visited[i][j] =1;
            solve(i, j+1 , m , n,ans ,  path+'R' , visited);
            visited[i][j]=0;
        }
        if(i-1>=0 && !visited[i-1][j] && m[i-1][j]==1){
            visited[i][j]=1;
            solve(i-1 , j , m , n , ans , path+'U', visited);
            visited[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
    // For lexogrphic order use DLRU movement 
    vector<string>ans;
    vector<vector<int>>visited(n , vector<int>(n , 0));
    if(m[0][0]==1)
    solve(0 , 0 , m ,n , ans ,"" , visited);
    return ans;
        // Your code goes here
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
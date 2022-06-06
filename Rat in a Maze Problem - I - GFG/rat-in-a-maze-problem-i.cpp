// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void helper(int x , int y , string&path , vector<vector<int>>&grid , int n){
        if(x == n-1 && y==n-1) {
            ans.push_back(path);
            return ;
        }
        int dy[]={0 , -1 ,1 , 0};
        int dx[]={1 , 0 ,0 , -1};
        char arr[]={'D','L','R','U'};
        for(int i=0 ; i < 4 ; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx >=0 && ny >=0 && nx <= n-1 && ny<=n-1) 
            // cout<<"nx = "<< nx <<"ny = "<<ny <<" grid = "<<grid[nx][ny]<<"\n";
            if(nx >=0 && nx <=n-1 && ny>=0 && ny <=n-1 && grid[nx][ny]==1){
                grid[nx][ny] = 2;
            //   1  cout<<"i = "<<i <<"arr[i] = "<<arr[i];
                path.push_back(arr[i]);
                // cout<<"Calling next Step \n";
                helper(nx ,ny , path , grid , n);
                grid[nx][ny] = 1;
                path.pop_back();
            }
        }
     return ;   
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string path = "";
        if(m[0][0] != 1 ) return {};
        m[0][0] =0;
        helper(0 , 0 , path , m , n);
        return ans;
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
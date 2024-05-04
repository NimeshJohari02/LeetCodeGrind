//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private : 
    void DFS(int i , int j , vector<vector<char>>&mat , vector<vector<bool>>&visited, int n , int m , int dx[] , int dy[]){
        visited[i][j] = true ;
        for(int k=0 ; k < 4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx>=0 && ny>=0 && nx < n && ny < m && !visited[nx][ny] && mat[nx][ny]=='O')
            DFS(nx , ny , mat , visited ,n , m ,dx,dy);
        }
        return ;
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , 1 , -1};
        vector<vector<char>>ans(n , vector<char>(m , 'X'));
        vector<vector<bool>>visited(n , vector<bool>(m , false));
        // Check Boundaries ;
        for(int j =0 ; j < m ; j++){
            if(mat[0][j]=='O' && !visited[0][j]){
                DFS(0 , j , mat , visited , n , m , dx , dy);
            }
             if(mat[n-1][j]=='O' && !visited[n-1][j]){
                DFS(n-1 , j , mat , visited , n , m , dx , dy);
            }
        }
        for(int i =0 ; i < n ; i++){
            if(mat[i][0]=='O' && !visited[i][0]){
                DFS(i , 0 , mat , visited , n , m , dx , dy);
            }
            if(mat[i][m-1]=='O' && !visited[i][m-1]){
                DFS(i , m-1 , mat , visited , n , m, dx , dy);
            }
          
        }
       for(int i=0 ; i < n ; i++)
        for(int j =0 ; j < m ; j++)
            ans[i][j] = visited[i][j] && mat[i][j]=='O'? 'O' : 'X';
       return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends

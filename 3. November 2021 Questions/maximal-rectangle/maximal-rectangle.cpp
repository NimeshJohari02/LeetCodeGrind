class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
     if(matrix.size()==0)   {
         return 0;
     }
      int row= matrix.size();
      int col=matrix[0].size();
      vector<vector<int>>dp(row+1, vector<int>(col+1,0)) , MaxidxAbove(row, vector<int>(col,1)) ,MaxidxBelow(row , vector<int>(col,1));
        for(int i=row-1 ; i >= 0 ; i--)
            for(int j=col-1 ; j>=0 ; j--)
                if(matrix[i][j]=='1')
                    dp[i][j]=dp[i][j+1]+1;
                
       
       stack<int>index;
       for(int j =0 ; j < col ; j++){
           index = stack<int>();
           for(int i=0 ; i < row ; i++){
               while(!index.empty() and dp[index.top()][j]>=dp[i][j]){
                   index.pop();
               }
                   MaxidxAbove[i][j] = i - (!index.empty() ? index.top() : -1);
                index.push(i);
           }
           index = stack<int>();
           for(int i =row-1 ; i>=0; i--){
               while(!index.empty() and dp[index.top()][j]>=dp[i][j]){
                   index.pop();
               }
                   MaxidxBelow[i][j] =  (!index.empty() ? index.top() : row) - i ;
                index.push(i);
               
           }
           
       }
        int ans =0;
                for(int i = 0; i < row; i++) 
            for(int j = 0; j < col; j++) 
                ans = max(ans, dp[i][j] * (MaxidxAbove[i][j]+MaxidxBelow[i][j]-1));
                    
        return ans;
    }
};
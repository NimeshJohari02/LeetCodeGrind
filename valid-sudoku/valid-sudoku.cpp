class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
     for(int i=0;i<9;i++){
         unordered_map<char,int>countRow;
         unordered_map<char,int>countCols;
       for(int j=0;j<9;j++){
         if((countRow[board[i][j]]!=0 and board[i][j]!='.') || (countCols[board[j][i]]!=0  and board[j][i]!='.')){
           return false;
         }
         else
         {
           countRow[board[i][j]]++;
           countCols[board[j][i]]++;
         }
       }
     }
     vector<vector<int>>temp = {{0,0}, {3,3}, {0,3}, {3,6}, {0,6}, {3,9},
    {3,0}, {6,3}, {3,3}, {6,6}, {3,6}, {6,9},
    {6,0}, {9,3}, {6,3}, {9,6}, {6,6}, {9,9}};
      for(int i=0;i<temp.size();i+=2){
        int is = temp[i][0];
        int js = temp[i][1];
         int ie = temp[i+1][0];
        int je = temp[i+1][1];
        unordered_map<char,int>mp;
        for(int k=is;k<ie;k++){ 
          for(int j=js ; j<je ;j++){
            if(mp[board[k][j]]!=0 && board[k][j]!='.'){
              return false;
            }
            mp[board[k][j]]++;
          }
        }
      }
      return true;
    }
};
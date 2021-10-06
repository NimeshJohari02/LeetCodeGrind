class Solution {
public:
    int board[10][10];
    vector<vector<string>>ans;
    bool isPossible(int n, int row, int col)
{
    //same col ;
    for (int i = row - 1; i >= 0;i--){
        if(board[i][col]==1)
        {
            return false;
        }
    }
    // Upper Left 
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--,j--){

        if(board[i][j]==1)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col +1 ; i >= 0 and j < n; i--,j++){
        if(board[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void nQueenHelper(int n , int row ){
    if(row == n ){
         vector<string>smallAns;
        for (int i = 0; i < n;i++)
        {
               string rowAns;
            for (int j = 0; j < n;j++){
               
                if(board[i][j]==1){
                   rowAns+="Q";
               }
                else{
                    rowAns+=".";
                }
            }
                smallAns.push_back(rowAns);
        }
        ans.push_back(smallAns);
        return ;
    }
    for (int i = 0; i < n;i++){
        if(isPossible(n,row,i)){
            board[row][i] = 1;
            nQueenHelper(n, row + 1);
            //BackTrack
            board[row][i] = 0;
        }
    }
    return;
}

    vector<vector<string>> solveNQueens(int n) {
    memset(board, 0, sizeof(board));
    nQueenHelper(n, 0);
    return ans;
    }
};
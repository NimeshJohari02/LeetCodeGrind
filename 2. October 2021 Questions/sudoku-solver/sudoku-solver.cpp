class Solution {
public:
    bool isPossible(vector<vector<char>>&board , int i , int j , int n , int num){
        char cmp= num+'0';
        for(int x = 0; x<n;x++){
             if(board[i][x]== cmp|| board[x][j]==cmp){
                 return false;
             }
         }
        int sx =(i/3)*3;
        int sy =(j/3)*3;
        for(int x = sx;x<sx+3;x++ ){
            for(int y=sy;y<sy+3;y++){
                if(board[x][y]==cmp){
                    return false;
                }
            }
        }
        return true;
    }
    bool solveHelper(vector<vector<char>>&board , int i , int j , int n ){
        if(i==n){
            // for(int al= 0 ; al<n ;al++){
            //     for(int bl =0;bl<n;bl++){
            //         cout<<board[al][bl]<<",";
            //     }
            //     cout<<endl;
            // }
            return  true;
        }
        //Next Row Going 
        if(j==n){
            return solveHelper(board,i+1,0,n);
        }
         //skip cell
        if(board[i][j]!='.'){
            return solveHelper(board,i,j+1,n);
        }
       // Rec Case 
        for(int num =1 ; num<=9;num++){
            if(isPossible(board, i , j , n , num)){
                board[i][j] = num+'0';
                bool canSolve=solveHelper(board,i,j+1,n);
                if(canSolve){
                    return true;
                }
            }
        }
        //BackTracking Step in which we tell ki 0-9 can't be placed hence;
        board[i][j]='.';
        // this to signify that by keeping anydigit we could not solve it thus change it 
        return false;
    }
    void solveSudoku(vector<vector<char>> &board) {
        solveHelper(board,0,0,board[0].size());
    }
};
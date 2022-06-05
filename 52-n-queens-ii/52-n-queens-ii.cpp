class Solution {
public:
int totalNQueens(int n) {
	vector<bool> col(n), ld(2*n-1), rd(2*n-1);
	return solve(col, ld, rd, 0);
}
   
int solve(vector<bool>& col, vector<bool>& ld, vector<bool>& rd, int row) {
	int n = size(col), count = 0;
    if(row == n) return 1;
	for(int column = 0; column < n; column++)           
		if(!col[column] && !ld[row + column] && !rd[row - column + n - 1]){     
			col[column] = ld[row + column] = rd[row - column + n - 1] = true;     
			count += solve(col, ld, rd, row + 1);                                  
			col[column] = ld[row + column] = rd[row - column + n - 1] = false;     
		}                                
	return count;
}
};
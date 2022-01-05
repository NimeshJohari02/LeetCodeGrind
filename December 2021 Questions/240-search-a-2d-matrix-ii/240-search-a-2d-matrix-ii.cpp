class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, r = 0, c = n - 1;
        while(r<m && c>=0){
        int corner= matrix[r][c];
            if(corner==target)
                return true;
            if(corner>target)c--;
            else if(corner < target)r++;
            
        }
        return false;
    }
};
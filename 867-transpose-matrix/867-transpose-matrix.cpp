class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>ans(cols,vector<int>(row));
        for(int r=0;r<row;r++){
            for(int c=0;c<cols;c++){
                ans[c][r]=matrix[r][c];
            }
        }
        return ans;
    }
};
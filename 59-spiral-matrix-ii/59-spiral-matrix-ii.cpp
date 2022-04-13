class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>arr(n, vector<int>(n,0));
         int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;
    int allElement = n * n;
    int counter = 0;
    while (rowStart <= rowEnd || colStart <= colEnd) {
      for (int i = colStart; i <= colEnd; i++) {
        arr[rowStart][i] = counter + 1;
        counter++;
      }
      if (counter == allElement) {
        break;
      }
      rowStart++;
      for (int i = rowStart; i <= rowEnd; i++) {
        arr[i][colEnd] = counter + 1;
        counter++;
      }
      if (counter == allElement) {
        break;
      }
      colEnd--;
      for (int i = colEnd; i >= colStart; i--) {
        arr[rowEnd][i] = counter + 1;
        counter++;
      }
      if (counter == allElement) {
        break;
      }
      rowEnd--;
      for (int i = rowEnd; i >= rowStart; i--) {
        arr[i][colStart] = counter + 1;
        counter++;
      }
      if (counter == allElement) {
        break;
      }
      colStart++;
    }
    return arr;
    }
};
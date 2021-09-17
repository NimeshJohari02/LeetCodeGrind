class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
  int rowStart=0;
  int rowEnd=arr.size()-1;
  int colStart=0;
      vector<int> ans;
  int colEnd=arr[0].size()-1;
  while (rowStart<=rowEnd && colStart<=colEnd)
{
    for (int i=colStart;i<=colEnd;i++ ){
            ans.push_back(arr[rowStart][i]);
    }
    rowStart++;
    for (int i=rowStart;i<=rowEnd;i++ ){
            ans.push_back(arr[i][colEnd]);
    }
    colEnd--;
	if(rowEnd>=rowStart){
    for (int i=colEnd;i>=colStart;i-- ){
            ans.push_back(arr[rowEnd][i]);
    }
    rowEnd--;
	}
	if(colEnd>=colStart){
    for (int i=rowEnd;i>=rowStart;i-- ){
            ans.push_back(arr[i][colStart]);
    }
    colStart++;
	}
}
      return ans;
    }
};
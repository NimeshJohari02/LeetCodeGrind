class Solution {
public:
    bool searchInRow(vector<int>&v,int target){
      int left =0;
      int right = v.size();
      while(right>=left){
        int mid = left+(right-left)/2;
        if(v[mid]==target){
          return true;
        }
        else if(v[mid]>target){
          right=mid-1;
        }
        else{
          left = mid +1;
        }
      }
      return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      for(int i=0;i<matrix.size();i++){
        int n = matrix[i].size();
        // cout<<"OUTSIDE For "<<target<<"MATRIX RANGE "<<matrix[i][0]<<"    ->    "<<matrix[i][n-1]<<endl;
        if(matrix[i].at(0)<=target && target<=matrix[i].at(n-1)){
            // cout<<"Inside For "<<target<<"MATRIX RANGE "<<matrix[i][0]<<"    ->    "<<matrix[i][n-1]<<endl;
        return searchInRow(matrix[i],target);  
        }
      }
      return false;
    }
};
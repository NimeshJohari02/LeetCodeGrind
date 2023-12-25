class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Brute Force is n*m search;
        // More optimized is binary Search . 
        // Seach C0 first then in the given Row apply BS 
        int r0=0 , r1 =matrix.size()-1;
        while(r1>r0){
            int mid = (r0+r1)>>1 ;
            // At every mid(th) row we need to check if the target is less than the next row start so that if it's more we can move to next row else this row has our solution. 
            if(matrix[mid+1][0]<=target) r0 = mid+1;
            else r1 = mid;
        }
        // Now we have column as r1 which has our data . We need to apply BS to the data that we have in row r1 . We can initialize a 
        int l=0 , r = matrix[0].size()-1 ;
        cout<<"R1 --> "<<r1<<"\n";
        while(r>=l){
            int mid= (r+l)>>1;
            if(matrix[r1][mid]==target) return true ;
            if(matrix[r1][mid]>target) r = mid-1;
            else l=mid+1;
        }
        return false ;
    }
};
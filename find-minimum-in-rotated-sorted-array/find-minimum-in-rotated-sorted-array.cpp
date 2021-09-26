class Solution {
public:
    int findMin(vector<int>& arr) {
        // Finding Pivot / Min Element;
      int s=0;
      int e=arr.size()-1;
      while(e>s){
        int mid = (s+(e-s)/2);
        if(arr[e]<arr[mid]){
          s=mid+1;
        }
        else{
          e=mid;
        }
      }
      return arr[s];
    }
};
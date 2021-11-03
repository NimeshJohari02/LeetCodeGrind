class Solution {
public:
    int findMin(vector<int>& arr) {
        int end = arr.size()-1;
        int start = 0;
        while(end>=start){
            int mid = (start+end)/2;
            if(arr[end]<arr[mid]){
                start=mid+1;
            }
            else if(arr[mid]>arr[end]){
                end = mid-1;
            }
            else{
                end--;   
            }
        }
        return arr[start];
    }
};
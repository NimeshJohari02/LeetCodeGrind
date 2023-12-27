class Solution {
public:
    int binarySearch(vector<int>&arr , int target , int s , int e){
        while(e>=s){
            int mid = (s+e)>>1 ;
            cout<<"MID ="<<mid <<"arr[mid] "<<arr[mid]<<"";
            if(arr[mid]==target)return mid ;
            else if(arr[mid]>target)e = mid-1;
            else s=mid+1;
        }
        return -1 ;
    }
    int search(vector<int>& arr, int target) {
           int start = 0 , end = arr.size()-1 , minIdx = arr.size() , minElement = INT_MAX;
        while(end>=start){
            int mid = (start+end)>>1 ;
            if(arr[mid]<minElement){
                minIdx = mid ;
                minElement = arr[mid];
            }
            if(arr[mid]>=arr[end])start = mid+1;
            else end = mid-1;
        }
        int pivot = minIdx ;
        int left  =  binarySearch(arr , target , 0 , pivot-1);
        if(left != -1)return left;
        return binarySearch(arr , target , pivot , arr.size()-1);
    }
};
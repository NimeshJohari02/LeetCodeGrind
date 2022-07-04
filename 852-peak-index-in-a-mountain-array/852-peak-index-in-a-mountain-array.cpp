class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1 , r = arr.size()-2;
        while(r >=l)
        {
            int mid = (l + r)>>1;
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
            if(arr[mid-1] > arr[mid]) r = mid-1;
            else l=mid+1;
        }
        return -1;
    }
};
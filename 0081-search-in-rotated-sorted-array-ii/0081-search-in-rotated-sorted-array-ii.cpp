class Solution {
public:
    bool search(vector<int>& arr, int target) {
        /*
        Input: nums = [2,5,6,0,0,1,2], target = 0
        Output: true
        here finding the Pivot is the main challenge as the pivot itself can be duplicated . we can have like 1 1 1 1 1 . 
        You must decrease the overall operation steps as much as possible.--> Means use Binary Search. No one wants linear solution. 
        */
        int s = 0 , e = arr.size()-1 ;
        while(e >= s){
            int mid = s + (e - s)/2 ;
            if(arr[mid]==target)return true ;
            if(arr[s]==arr[mid] && arr[mid]==arr[e]){s++ ; e--; continue;}
            if(arr[e] >= arr[mid]){
                if(arr[mid]<=target && arr[e]>=target) s=mid+1;
                else e = mid-1 ;
            }
            else {
                if(arr[s]<=target && target <= arr[mid])
                    e = mid-1 ;
                else s = mid+1 ;
            }
        }
        return false ;
    }
};
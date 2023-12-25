class Solution {
public:
    int findMin(vector<int>& arr) {
        // We have to return the arr[OriginalIdx] . Here OriginalIdx is the idx about which the array is rotated . 
        int start = 0 , end = arr.size()-1 ;
        while(end>start){
            int mid = (start+end)>>1 ;
            if(arr[mid]>=arr[end])start = mid+1;
            else end = mid;
        }
        // cout<<start<<" "<<end<<"\n";
        return arr[end];
    }
};
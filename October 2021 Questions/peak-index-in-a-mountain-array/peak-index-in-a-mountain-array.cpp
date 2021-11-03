class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i =0;
        int j = arr.size()-1;
        while(i<j){
            if(arr[i+1]>arr[i]){
                i++;
            }
            if(arr[j-1]>arr[j]){
                j--;
            }
        }
        return j;
    }
};
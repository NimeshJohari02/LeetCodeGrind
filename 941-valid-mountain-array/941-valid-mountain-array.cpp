class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0; 
        /// Increasing 
        while(i+1<arr.size()  && arr[i]<arr[i+1]) i++;
        // Peak
        if(i==0 || i==arr.size() -1) return false; 
        // Decreasing
        while(i+1< arr.size() and arr[i]>arr[i+1]) i++;
        return i==arr.size()-1;
    }
};
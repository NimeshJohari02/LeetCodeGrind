class Solution {
public:
    int hIndex(vector<int>& arr) {        
        int start = 0 ;
        int end = arr.size()-1;
        sort(arr.begin() , arr.end());
        while (start <= end) {
            int mid = (end+start)>>1;
            if (arr[mid] < arr.size() - mid) 
                start = mid + 1;
            else end = mid - 1;
        }
        return arr.size() - start;
    }
};
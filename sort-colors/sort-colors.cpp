class Solution {
public:
    void sortColors(vector<int>& arr) {
   int lo = 0;
    int hi = arr.size() - 1;
    int mid = 0;
 
    while (mid <= hi) {
        switch (arr[mid]) {
     case 0:
            swap(arr[lo++], arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }
    }
};
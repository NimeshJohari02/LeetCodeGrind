class Solution {
public:
    int minimizedMaximum(int n, vector<int>& arr) {
        int low = 1;
        int high = 1e5;
        int ans = high ;
        while(low<=high){
            int mid = (low+high)/2;
            int count =0;
            for(auto it : arr){
                count+= it/mid;
                if(it %mid ) count++;
            }
            if(count <= n){
                ans= mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans ;
    }
};
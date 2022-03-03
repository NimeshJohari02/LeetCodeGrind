class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3){
            return 0;
        }
        //Here LIS is not subsequence it is contiguos therefore Can be done in O(n)
       vector<int>LIS(arr.size(), 0);
       vector<int>LDS(arr.size(), 0);
        for(int i =0 ; i < arr.size()-1; i++){
                if(arr[i+1]>arr[i]){
                    LIS[i+1]=1+LIS[i];
            }
        }
        for(auto it : LIS){
            cout<<it<<"  ";
        }
       cout<<endl; 
        for(int i=arr.size()-2 ; i >=0 ; i--){
                if(arr[i]>arr[i+1]){
                    LDS[i]=  1+ LDS[i+1];
                }
            }
        for(auto it: LDS)
            cout<<it<<"  ";
        cout<<endl;
        int ans =0;
        for(int i=0 ; i < LDS.size() ; i++){
            if(LIS[i] and LDS[i])
                ans = max(ans, LIS[i] + LDS[i] + 1);
        }
        return ans;
        }
};
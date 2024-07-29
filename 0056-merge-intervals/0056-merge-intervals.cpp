class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end());
         vector<vector<int>>ans;
        int n = arr.size();
        if(n==1)return arr;
        ans.push_back(arr[0]);
        for(int i=1 ;  i < n ; i++){
            auto currInterval = arr[i];
            auto prevInterval = ans.back();
            if(prevInterval[1] >= currInterval[0]){
                ans.back()[1] = max(currInterval[1] , prevInterval[1]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans ; 
    }
};
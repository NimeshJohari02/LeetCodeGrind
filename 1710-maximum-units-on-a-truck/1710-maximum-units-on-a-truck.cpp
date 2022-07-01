class Solution {
public:
    static bool cmp(const vector<int>& v1 , const vector<int>& v2){
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& arr, int maxi) {
        sort(arr.begin() , arr.end() , cmp);
        int ans =0 ;
        for(auto &it : arr){
            if(maxi <=0 ) break;
            else{
                ans += min(it[0] , maxi) * it[1];
                maxi -= it[0];
            }
        }
        return ans;
    }
};
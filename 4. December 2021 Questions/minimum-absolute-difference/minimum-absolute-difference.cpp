class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        map<int,vector<vector<int>>>mp;
        sort(arr.begin(),arr.end());
        int mx = INT_MAX;
        for(int i=0 ; i<arr.size()-1; i++){
            mp[abs(arr[i]-arr[i+1])].push_back({arr[i],arr[i+1]});
            mx = min(abs(arr[i]-arr[i+1]) , mx);
        }
        return mp[mx];
    }
};
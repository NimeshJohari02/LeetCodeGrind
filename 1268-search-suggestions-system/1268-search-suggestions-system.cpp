class Solution {
public:
    vector<string> binarySearch(vector<string>&arr , string query){
        int i=0 ;
        int j = arr.size() -1 ;
        vector<string> ans;
        auto it = lower_bound(arr.begin(), arr.end(), query);
            for (int i = 0; i < 3 && it + i != arr.end(); i++) {
                string& s = *(it + i);
                if (s.find(query)) break;
                ans.push_back(s);
            }
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& arr, string q) {
        // Sort and Binary Search Prefix append idx to new arr and return 
        sort(arr.begin() , arr.end());
        for(auto &it : arr)cout<<it<<"  ";
        vector<vector<string>> ans;
        string cq = "";
        for(int i=0 ; i < q.size() ; i++){
            cq += q[i];
            ans.push_back(binarySearch(arr , cq));
        }
    return ans;
    }
    
};
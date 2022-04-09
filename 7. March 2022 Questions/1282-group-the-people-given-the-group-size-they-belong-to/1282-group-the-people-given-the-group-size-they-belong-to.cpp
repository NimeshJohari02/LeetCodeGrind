class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>> ans; 

        map<int, vector<int>> mp; 
        int n = arr.size(); 
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i); 
        }

        for(auto& it : mp) {
            int size = it.first; 
            int i = 0; 
            while(i<it.second.size()) {
                vector<int> temp; 
                for(int j = 0; j < size; j++) {
                    temp.push_back(it.second[i]);
                    i++;
                }
                ans.push_back(temp); 
            }

        }
        return ans; 
    }
}; 
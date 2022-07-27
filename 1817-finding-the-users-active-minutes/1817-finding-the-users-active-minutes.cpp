class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int , unordered_set<int>>mp ;
        for(auto &it : logs)
            mp[it[0]].insert(it[1]);
        vector<int>ans(k , 0);
        for(auto &it : mp)
            ans[it.second.size()-1]++;
        return ans;
    }
};
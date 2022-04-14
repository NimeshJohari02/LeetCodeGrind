class Solution {
public:
    vector<string> ans;
    unordered_map<string , priority_queue<string , vector<string > , greater<string >> > mp;
    void dfs(string str){
        auto &it = mp[str];
        while(it.size() !=0 ){
            string to = it.top();
            it.pop();
            dfs(to);
        }
        ans.push_back(str);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &it : tickets){
            mp[it[0]].push(it[1]);
        }
        
        dfs("JFK");
        reverse(ans.begin() , ans.end() ) ;
        return ans ;
    }
};
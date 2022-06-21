class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
 vector<vector<int>> ans(2);
    map<int,int> mp;
    for(auto i:arr){
        if(!mp.count(i[0])) mp[i[0]]=0;
        mp[i[1]]++;
    }
    for(auto &it :mp){
        if(it.second == 0) ans[0].push_back(it.first);
        
        else if(it.second == 1) ans[1].push_back(it.first);
    }
        return ans;
    }
};
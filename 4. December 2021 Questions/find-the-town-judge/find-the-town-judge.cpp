class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,vector<int>>mp;
        map<int,vector<int>>mpp;
        if(trust.size() ==0){
            if(n==1){
                return 1;
            }
            return -1;
        }
        vector<int>candidates;
        for(auto &it : trust){
                mp[it[1]].push_back(it[0]);
                mpp[it[0]].push_back(it[1]);
        }
        for(int i=0 ; i <= n ; i++){
            if(mp[i].size()==n-1)
                candidates.push_back(i);
        }
        for(auto &it:candidates){
            if(mpp[it].size()==0)
                return it;
        }
        return -1;
    }
};
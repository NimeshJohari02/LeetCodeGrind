class Solution {
public: 
    bool carPooling(vector<vector<int>>& arr, int capacity) {
       map<int,int>mp;
        //1st coor 2nd people 
        for(auto &it : arr){
            mp[it[1]]+=it[0];
            mp[it[2]]-=it[0];
        }
    int num =0;
        for(auto &it : mp){
            num+=it.second;
            if(num>capacity)return false;
        }
        return true;
    }
};
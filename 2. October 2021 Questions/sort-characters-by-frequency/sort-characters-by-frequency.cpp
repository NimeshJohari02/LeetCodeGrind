class Solution {
public:
    static bool cmp(pair<char,int>p1 , pair<char,int>p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        vector<pair<char,int>>mpArr;
        for(auto it : mp){
            mpArr.push_back({it.first,it.second});
        }
        sort(mpArr.begin(),mpArr.end(),cmp);
        string ans;
        
        for(auto it : mpArr){
            // cout<<it.first<<it.second<<endl;
            while(it.second--){
                ans +=it.first;
            }
        }
        return ans;
    }
};
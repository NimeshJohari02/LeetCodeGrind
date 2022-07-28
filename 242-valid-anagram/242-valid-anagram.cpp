class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>mp(26 , 0);
        for(auto &it : s) mp[it-'a']++;
        for(auto&it : t) mp[it-'a']--;
        for(int i=0 ; i < 26 ; i++) if(mp[i] != 0)return false;
        return true;
    }
};
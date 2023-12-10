class Solution {
public:
    bool mapAns(string&s , string&t){
        map<char , int>mp ;
        for(auto &it : s)mp[it]++;
        for(auto&it:t)mp[it]--;
        for(auto&it:mp)if(it.second!=0)return false;
        return true;
    }
    bool arrAns(string &s , string &t){
        vector<int>mp(26,0);
        for(auto &it:s)mp[it-'a']++;
        for(auto &it :t)mp[it-'a']--;
        for(auto &it : mp) if(it != 0)return false ;
        return true ;
    }
    bool isAnagram(string s, string t) {
        return arrAns(s , t);
    }
};
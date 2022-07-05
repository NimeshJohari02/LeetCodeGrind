class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char , char > mp;
        int i = 0 ;
        for(auto &it : key)
        {
            if(it ==' ')continue;
            if(mp.find(it) != mp.end()) continue;
            else mp[it] = i+'a';
            i++;
        }
        string ans = "";
        for(auto &it : message){
            if(it == ' ') {ans +=" "; continue ; }
            else ans += mp[it];
        }
        return ans;
    }
};
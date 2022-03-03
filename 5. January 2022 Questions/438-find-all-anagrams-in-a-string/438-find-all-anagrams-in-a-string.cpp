class Solution {
public:
    bool isAnagram(vector<int>mp , string&pattern){
        for(auto &it:pattern)
            mp[it-'a']--;
        bool ans=true;
        for(auto&it:mp)
            if(it !=0)
                ans = false;
        return ans;
    }
    vector<int> findAnagrams(string s, string p) {
     vector<int>stringMap(26 , 0);
        vector<int>ans;
        int i=0;
        int j =0;
        int n = s.size();
    while(i<n && j < n){
            int ch = s[j]-'a';
            stringMap[ch]++;
            if(j-i+1 < p.size()){
                j++;
            }
            else if(j-i+1 == p.size()){
                if(isAnagram(stringMap , p)){
                    ans.push_back(i);
                }
                j++;
            }
             if((j-i+1)>p.size()){
                while(j-i+1 > p.size() && i <s.size()){
                    stringMap[s[i]-'a']--;
                    i++;
                }
            }
    }
        return ans;
    }
};
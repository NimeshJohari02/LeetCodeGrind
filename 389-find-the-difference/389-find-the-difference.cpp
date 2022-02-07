class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[26]= {0};
        for(auto&it:t)
            a[it-'a']++;
        for(auto&it:s)
            a[it-'a']--;
        for(int i=0 ; i < 26;i++)
            if(a[i]!=0)
                return i+'a';
        return 'a';
    }
};
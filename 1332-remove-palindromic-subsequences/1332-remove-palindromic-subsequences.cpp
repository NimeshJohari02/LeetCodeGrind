class Solution {
public:
    bool isP(string &s){
        int i=0 , j =s.size()-1;
        while(j>=i)
            if(s[i++]!=s[j--])
                return false;
        return true;
    }
    int removePalindromeSub(string s) {
        bool p = isP(s);
        return p ? 1 : 2;
    }
};
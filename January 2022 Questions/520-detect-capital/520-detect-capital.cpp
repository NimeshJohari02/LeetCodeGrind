class Solution {
public:
    bool detectCapitalUse(string word) {
        int lenCaps =0;
        bool isFirstCaps = isupper(word[0]);
        for(auto &it : word){
            if(isupper(it))
                lenCaps++;
        }
        if((lenCaps == word.size() && isFirstCaps) || lenCaps ==0 || (isFirstCaps && lenCaps ==1)) 
            return true;
        return false;
    }
};
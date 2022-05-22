class Solution {
public:
    bool differByOne(string &s1 , string &s2){
        // s1 is the larger string 
        if(s1.size() != s2.size()+1) return false;
        int i=0 , j =0 ;
        while(i < s1.size()){
            if(s1[i] == s2[j]){
                i++;j++;
            }
            else
                i++;
        }
        if(s1.size() == i && s2.size() == j) return true;
        return false;
    }
    static bool cmp(string &s1 , string &s2){
        return s1.size() < s2.size() ;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size() ;
        sort(words.begin() , words.end() , cmp);
        vector<int>dp(n+1 , 1);
        for(int i=0 ; i < n ; i++){
            for(int j =0 ; j < i ; j++){
                if(differByOne(words[i] , words[j]) && 1+dp[j]>dp[i]){
                    dp[i] = 1+ dp[j];
                }
            }
        }
        int mn = INT_MIN;
        for(auto &it : dp)
            mn = max(mn,it);
        return mn;
    }
};
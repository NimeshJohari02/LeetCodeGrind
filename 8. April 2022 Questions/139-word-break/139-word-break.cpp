
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict ;
        for(auto &it : wordDict) dict.insert(it);
        vector<bool>dp(s.size() +1, false);
        dp[0] = true;
        for(int i=1 ; i <= s.size() ;i++)
        {
            for(int j = i-1 ;  j>=0 ; j--)
            {
                if(dp[j]){
                    if(dict.find(s.substr(j ,i - j)) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
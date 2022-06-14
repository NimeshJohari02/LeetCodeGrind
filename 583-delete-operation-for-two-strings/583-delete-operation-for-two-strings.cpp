class Solution {
public:
    int lcs(string &s1 , string &s2){
        // vector<vector<int>>dp(s1.size() +1 , vector<int>(s2.size() +1 , 0));
        vector<int> prev(s2.size()+1 , 0);
        vector<int>curr(s2.size() +1 , 0);
        for(int i=1 ; i <=s1.size() ; i++)
        {
            for(int j = 1 ;  j<=s2.size() ; j++)
            {
                if(s1[i-1] == s2[j-1]){
                    curr[j]  =  1+prev[j-1];
                }
                else{
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[s2.size()];
    }
    int minDistance(string word1, string word2) {
       // DP on string typical question
        // return rec(word1.size()-1 , word2.size()-1 , word1 , word2);
        int lcsLen = lcs(word1 , word2 );
        return word1.size() + word2.size() - 2*lcsLen;
    }
};
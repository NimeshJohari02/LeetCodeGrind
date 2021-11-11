class Solution {
public:
    int lcs(string s1 , string s2){
        int dp[s1.length()+1][s2.length()+1];
        memset(dp ,0 , sizeof(dp));
        for(int i =1 ; i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
    int minDistance(string word1, string word2) {
        int lcsLen = lcs(word1,word2);
        return ((word1.length()-lcsLen)+(word2.length()-lcsLen));
    }
};
class Solution {
public:
    int lps(string s1){
        string s2(s1);
        reverse(s2.begin(),s2.end());
        int dp[s1.length()+1][s2.length()+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
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
    int minInsertions(string s) {
        return s.length()-lps(s);
    }
};
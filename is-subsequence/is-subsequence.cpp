class Solution {
public:
    int lcs(string s1 , string s2){
        int dp[s1.length()+1][s2.length()+2];
        memset(dp,0,sizeof(dp));
        for(int i=1 ; i<=s1.length();i++){
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
    bool isSubsequence(string s, string t) {
        int ll = lcs(s, t);
    if(ll == s.size()){
            return true;
        }
        return false;      
    
    }
};
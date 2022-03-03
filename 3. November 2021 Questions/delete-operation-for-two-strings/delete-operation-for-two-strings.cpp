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

/* Another Space Optimised  solution for the same . 
Rather than storing all the states we can store only the dp of prev 2 rows . then we could save up some space
This is the approach from the discuss section and can be use full when you have to optimize space to a maximum 
Since we only have 2 possible values for i ie 0 and 1 . Doing an AND with 1 would returnn the current Index in which the 
*/
int minDistance(string& word1, string& word2) {        
    if(size(word1) < size(word2)) swap(word1, word2);
	vector<vector<int> >dp(2, vector<int>(size(word2) + 1));
	for(int i = 0; i <= size(word1); i++) 
		for(int j = 0; j <= size(word2); j++) 
			if(!i || !j) dp[i & 1][j] = i + j;
			else dp[i & 1][j] = word1[i - 1] == word2[j - 1] ? dp[(i - 1) & 1][j - 1] : 1 + min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
	return dp[size(word1) & 1][size(word2)];
}

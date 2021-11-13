class Solution {
public:
    int dp[2001][2001];
    bool isPallindrome(string &s , int i , int j){
    while (j>=i)
    {
        if(s[j]!=s[i]){
            return false;
        }
        j--;
        i++;
    }
    return true;
}
int memoized(string &s, int i, int j)
{
    if(i>=j){
        return dp[i][j]= 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(isPallindrome(s,i,j)){
            return dp[i][j]= 0;
    }
    
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = 1 + memoized(s, i, k) + memoized(s, k + 1, j);
        mn = mn > temp ? temp : mn;
    }
    return dp[i][j]=mn;
}
    int minCut(string s) {
        // memset(dp,-1,sizeof(dp));
        // return memoized(s,0,s.length()-1);
        
        if(s.size() <= 1)
      return 0;
 int n = s.size();
 vector<int> cut(n+1, 0); 
  for (int i = 0; i <= n; i++) 
            cut[i] = i-1;
  for (int i = 0; i < n; i++) 
  {
          for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) 
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

         for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) 
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
    
    
};
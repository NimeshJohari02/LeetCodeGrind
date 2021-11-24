class Solution {
public:
    int helper(string &s1 , int left , int right , vector<vector<int>>&dp){
        // Since for every Single elment we have to consider it as a pallindrome ;
        if(left>=right){
            return 1;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(s1[left]==s1[right]){
            return dp[left][right] = helper(s1 , left+1, right-1, dp);
        }
        //Since SubString Not Subsequence Simply Put 0 for this
        return dp[left][right]=0;
    }
    int countSubstrings(string &s1) {
        vector<vector<int>>dp(s1.size() , vector<int>(s1.size() , -1));
        int ans =0;
        for(int i = 0; i<s1.size() ; i++ ){
            for(int j=i; j<s1.size() ; j++){
                ans += helper(s1 , i , j , dp);
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool isLongerChain(vector<int> &p1 , vector<int> &p2){
        return p2[0] > p1[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end());
        int n = pairs.size();
        vector<int>dp(n+1 , 1);
        for(int i=0 ; i <=n-1 ; i++){
            for(int j =0 ; j <= i ; j++){
                if(isLongerChain(pairs[j] , pairs[i]) && dp[j] +1 > dp[i]){
                    dp[i] =1+dp[j];
                }
            }
        }
    int mn = INT_MIN;
        for(auto &it : dp)
            mn = max(it , mn);
        return mn ;
    }
    
};
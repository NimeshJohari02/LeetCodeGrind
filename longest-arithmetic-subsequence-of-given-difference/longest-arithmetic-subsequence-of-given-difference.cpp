class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
       /* Longest Increasing Subsequence;
        This N^2 Approach Using LIS Gives TLE
        vector<int>dp(arr.size(), 1);
        int n = arr.size();
        for(int i=0 ; i < n ; i++){
            int mx = 0;
            for(int j = i-1 ; j>=0 ; j--){
                if((arr[i]-arr[j]) == difference ){
                    mx = max(mx , dp[j]);
                }
            }
            dp[i]=mx+1;
        }
        int ans = INT_MIN;
        for(auto it : dp )
            ans = max(ans , it);
        return ans;*/
        
        // Better Approach is to use a hashmap and find the term of the AP and Tn = a+ (n-1)d;
        unordered_map<int,int>mp;
        int mx = 1;
        for(auto it :arr){
            mp[it]= mp[it-difference]+1;
           mx = max(mx , mp[it]) ;
        }
        return mx;
    }
};
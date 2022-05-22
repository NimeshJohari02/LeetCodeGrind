class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n+1 , 1);
        vector<int>cnt(n+1 , 1);
        int maxi = INT_MIN;
        for(int i=0 ; i < n ; i++){
            for(int j= i-1 ; j >=0 ; j--){
                if(arr[i] > arr[j] && dp[j]+1 > dp[i]){
                    dp[i] = 1+dp[j];
                    cnt[i]= cnt[j];
                }
                else if(arr[i] > arr[j] && dp[j]+1 == dp[i]){
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi , dp[i]);
        }
        int ans = 0;
        for(int i=0 ; i < n  ; i++)
            if(dp[i] == maxi)
                ans+=cnt[i];
        return ans;
    }
};
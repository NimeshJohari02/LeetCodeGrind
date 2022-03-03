class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[nums1.size()+1][nums2.size()+1];
        memset(dp,0,sizeof(dp));
        for(int i =1 ; i <=nums1.size();i++){
            for(int j =1 ; j<= nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
              }
        }
        int ans =0;
    for(int i = 0 ;i <= nums1.size();i++){
        for(int j =0 ; j<=nums2.size(); j++){
            ans = max(ans , dp[i][j]);
        }
    }
    return ans;
    }
};
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/1324248/C++Python-DP-KMP-Hashing-Solutions-Clean-and-Concise-O(NlogN)
// This solution post has solutions that I have not covered till now which include KMP and Rolling Hash get back to it once you are done with those topics 

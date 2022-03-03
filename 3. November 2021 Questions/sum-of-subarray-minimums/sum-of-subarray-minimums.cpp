//https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/JavaC%2B%2BPython-Stack-Solution
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>>stkLeft , stkRight;
        int n = arr.size();
        vector<int> left(n), right(n);
        int mod = 1e9+7;
        // Computing NSL -> Nearest Smallest To the Left and  NSR -> Nearest Smallest To the right and store their Index in the left and right 
        //NSL
        for(int i=0 ; i<n ; i++){
            int idx =1;
            while(!stkLeft.empty() and stkLeft.top().first>arr[i]){
                idx+=stkLeft.top().second;
                stkLeft.pop();
            }
            stkLeft.push({arr[i],idx});
            left[i]=idx;
        }
        
        //NS
        for(int i=n-1 ;i>=0 ; i--){
            int idx =1;
            while(!stkRight.empty() and stkRight.top().first>=arr[i]){
                idx+=stkRight.top().second;
                stkRight.pop();
            }
            stkRight.push({arr[i],idx});
            right[i]=idx;
        }
        unsigned long ans =0;
        for(int i=0 ; i< n ; i++){
            ans = (ans+ (long)arr[i]*right[i]*left[i])%mod;
        }
        return ans;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size(),sum=0,ans=0,mod=1e9+7;
        int numberOfOdd=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum&1){
                ans=(ans+i-numberOfOdd+1)%mod;
                numberOfOdd++;
            }else{
                ans=(ans+numberOfOdd)%mod;
            }
        }
        return ans;
        
    }
};
typedef  long long int ll ;
class Solution {
public:
    
    int numSub(string s) {
        // n*n+1/2
        ll  ans =0;
        ll  count =0;
        ll  mod = 1e9+7;
        ll  i=0;
        while(i<s.length()){
            if(s[i]=='1'){
                count++;
            }
            else
            {
                ans=((ans+(count*(count+1)/2)) % mod);
                count =0;
            }
            i++;
        }
            if(count !=0){
                ans=((ans+(count*(count+1)/2)) % mod);
            }
        return ans%mod;
    }
};
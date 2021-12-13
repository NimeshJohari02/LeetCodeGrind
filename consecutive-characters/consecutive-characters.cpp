class Solution {
public:
    int maxPower(string s) {
        int curr =1;
        int ans =1;
        char prev = s[0];
        for(int i=1 ; i <s.length();i++){
            if(prev ==s[i])
            curr++;
        else{
            ans = max(curr ,ans );
            prev = s[i];
            curr = 1 ;
        }
        }
    ans = max(curr ,ans ); 
    return ans;
    }
};
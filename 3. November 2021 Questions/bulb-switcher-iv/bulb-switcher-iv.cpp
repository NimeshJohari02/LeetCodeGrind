class Solution {
public:
    int minFlips(string s) {
        int  i =0;
        int ans =0;
        while(s[i]!='1' and i <s.length()){
            i++;
        }
        if(i==s.length()){
            return 0;
        }
        ans +=1;
        char prev = s[i];
        while(i!=s.length()){
            if(s[i]==prev){
                i++;
            }
            else{
                ans++;
                prev = s[i];
            }
        }
        return ans ;
        // prev rakh ke krlo
        
    }
};
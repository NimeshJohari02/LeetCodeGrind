class Solution {
public:
    int numSteps(string s) {
        int carry = 0  , ans = 0 ;
        // multiply by 2 and left shift --> push_back and add 0 
        while(s.size() != 1){
            if(s.back()=='1'){
                carry = 1;
                for(int i= s.size()-1; i >=0 ; i--){
                    if(s[i] == '1' && carry) s[i] = 0;
                    else if(s[i]=='0' && carry){
                        s[i] = '1' ;
                        carry =0 ;
                        break;
                    }
                }
                if(carry){
                    s.insert(0 , "1");
                }
                ans++;
            }
            else{
                // divide by 2 and increment 
                s.pop_back();
                ans++;
            }
        }
        if(s=="0"){
            ans++;
        }
     return ans;   
    }
};
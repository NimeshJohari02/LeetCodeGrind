/*
11111222223 - > 
 1-  5        15
 2 -5         30
 3 - 1 *3 = 3
*/

class Solution {
public:
    string digitSum(string s, int k) {
       while(s.length()>k){
           string res ="";
           int sum =0 ;
           for(int i=0 ; i < s.size() ; i++){
               if(i % k == 0 && i != 0){
                   res+=to_string(sum);
                   sum=0;
               }
            sum+=(s[i]-'0');
           }
           res+=to_string(sum);
           s = res;
           res = "";
       }
        return s;
    }
};
class Solution {
public:
    string replaceDigits(string s) {
    // s[n-i-1] =  (((long long int)(s[n-i-1]-'a'))+leftSum)%26+'a';
    for(int i=1;i<=s.length()-1;i++){
      if(i%2!=0){
        s[i]=((s[i-1]-'a')+(s[i]-'0'))+'a';
      }
    }  
      return s;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
      int count =0;
      int effectiveLength=s.length()-1;
      if(s[effectiveLength]==' '){
        while(s[effectiveLength]==' ' and effectiveLength>0){
          effectiveLength--;
        }
      }
        for(int i=effectiveLength;i>=0;i--){
          if(s[i]==' '){
            return count;
          }
          else{
            count++;
          }
        }
    return count;
    }
};
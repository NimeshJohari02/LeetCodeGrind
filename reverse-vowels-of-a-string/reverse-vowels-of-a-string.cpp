class Solution {
public:
  bool isVowel(char ch){
    ch=tolower(ch);
    if(ch == 'a' || ch =='e' || ch =='i'|| ch =='o'|| ch=='u'){
      return true;
    }
    return false;
  }
    string reverseVowels(string s) {
        int i=0;
        int j = s.length()-1;
        while(j>i){
          if(isVowel(s[i]) and isVowel(s[j])){
            swap(s[i],s[j]);
            i++;j--;
          }
          else if(!isVowel(s[i])){
            i++;
          }
          else if(!isVowel(s[j])){
            j--;
          }
          else{
            i++;
            j--;
          }
        }
      return s;
    }
};
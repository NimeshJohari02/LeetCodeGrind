class Solution {
public:
    string reversePrefix(string word, char ch) {
  for(int i=0;i<word.length();i++){
      if(word[i]==ch){
         for(int j=0;j<=i/2;j++){
           swap(word[j],word[i-j]);
         }
         return word;
       }
   }
    
     return word; 
    }
};
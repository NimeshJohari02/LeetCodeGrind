class Solution {
public:
    string reverseWords(string str) {
        vector<string>words;
      //trim(str);
        string word;
      int i=0;
      while(i<=str.length()){
        if(str[i]==' ' or str[i]=='\0'){
          // cout<<str[i]<<"  ";
        if(word.length()!=0){
            words.push_back(word);
            word="";
          }
        }
        else{
          word+=str[i];
        }
          i++;

      }
       // cout<<words.size();
      int n = words.size();
      for(int i=0;i<n;i++){
        reverse(words[i].begin(),words[i].end());
      }
      string ans ="";
      // for(auto i : words)
      for(int i=0;i<=n-2;i++){
        ans+=words[i];
        ans+=' ';
      }
      ans+=words[n-1];
      return ans;
 
    }
};
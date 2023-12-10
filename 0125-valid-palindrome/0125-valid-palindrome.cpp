class Solution {
public:
    bool isPalindrome(string str) {
    string ans ="";
    for(auto it:str)
      if(iswalnum(it))
          ans+=tolower(it);
    for(int i=0;i<ans.length()/2;i++)
      if(ans[i]!=ans[ans.length()-i-1]) 
          return false;
      return true;
    }
};
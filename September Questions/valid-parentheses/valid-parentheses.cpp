class Solution {
public:
    bool isValid(string s) {
      stack<char> stk;
      if(s.length()%2!=0){
        return false;
      }
      for(int i=0;i<s.length();i++){
        if(s[i]==']' || s[i]=='}' || s[i]==')'){
          if(stk.empty()){
            return false;
            break;
          }
          char opening=stk.top();
          char closing=s[i];
          if(opening=='(' and closing==')'){
            stk.pop();
          }
          else if(opening=='{' and closing=='}'){
            stk.pop();
          }
          else if(opening=='[' and closing==']'){
            stk.pop();
          }
          else{
          return false;
          }
        }
        else
        {
          stk.push(s[i]);
        }
      }
      if(stk.empty())
        return true;
  return false;
    }
};
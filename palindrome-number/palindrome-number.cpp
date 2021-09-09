class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0){
        return false;
      }
      int init=x;
      long long int ans =0;
      while(x){
        ans=ans*10+(x%10);
        x=x/10;
      }
      return ans==init;
    }
};
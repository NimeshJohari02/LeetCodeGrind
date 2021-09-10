class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
      long long int leftSum=0;
      int n = shifts.size();
      for(int i=0;i<n;i++){
        leftSum += shifts[n-i-1];
        s[n-i-1] =  (((long long int)(s[n-i-1]-'a'))+leftSum)%26+'a';
      }
      return s;
    }
};
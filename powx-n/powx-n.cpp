class Solution {
public:
    // long double ans =1;
    double myPow(double x, int n) {
      if(n==0){
        return 1;
      }
      if(n==1){
        return x;
      }
      if(n<0){
        n=abs(n);
        x=1/x;
      }
       long double ans = myPow(x,floor(n/2));
      if(n%2!=0){
        return ans*ans*x;
      }
      return ans*ans;
    }
};
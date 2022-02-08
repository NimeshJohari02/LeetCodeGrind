class Solution {
public:
    // int r(int n){
    //     if(n<10)
    //         return n;
    //     int s=0;
    //     while(n){
    //         s += n%10; 
    //         n /=10; 
    //     }
    //     return r(s);
    // }
    int helper(int n) {
  if (n <= 9)
    return n;
  while (1) {
    if (n <= 9)
      return n;
    int temp = n;
    int sum = 0;
    while (temp) {
      int ld = temp % 10;
      temp /= 10;
      sum += ld;
    }
    n = sum;
  }
}
    int addDigits(int num) {
        return helper(num);
    }
};
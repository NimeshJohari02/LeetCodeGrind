class Solution {
public:
    bool isPrime(int n){
      if(n==1){
        return false;
      }
      for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
          return false;
        }
      }
      return true;
    }
    int countSetBits(int n){
      int count =0;
      while(n){
        count++;
        n=n&(n-1);
      }
      return count;
    }
    int countPrimeSetBits(int left, int right) {
      int ans =0;  
      for(int i=left ; i <=right;i++){
        // int setBits=countSetBits(i);
        // cout<<"Number "<<i<<"Set Bits "<<setBits<<" is Prime"<<isPrime(setBits)<<endl;
//         isPrime(__builtin_popcount(i)
        if(isPrime(countSetBits(i))){
          ans++;
        }
      }
      return ans;
    }
};
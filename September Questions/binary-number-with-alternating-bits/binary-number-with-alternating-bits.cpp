class Solution {
public:
    bool hasAlternatingBits(int n) {
     bool hasBits=true;
      // if(n==1){
      //   return true;
      // }
      // cout<<(1>>1);
      while(n){
        hasBits = ((n&1)^((n>>1)&1))==1?true:false;
        if(hasBits==false){
          return hasBits;
        }
        n=n>>1;
        }
      return hasBits;
    }
};
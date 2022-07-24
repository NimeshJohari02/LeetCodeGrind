class Solution {
public:
    // int getSum(int a, int b) {
       //  vector<int>ba(32 , 0) , bb(32 , 0);
       //  for(int i=0 ; i < 32 ; i++){
       //      ba[i] = a & (1 << i);
       //      bb[i] = a & (1 << i);
       //  }
       //      int carry = 0 ;
       //  int i;
       //  for(i=0 ; i < 32 ; i++){
       //      if(ba[i] ==1 && bb[i]==1 && carry==1){
       //          ba[i] = 1 ;
       //          carry = 1;
       //          continue;
       //      }
       //      else if(ba[i]==1 && bb[i]==0 &&carry ==1){
       //          ba[i] =1 ;
       //          carry =0 ;
       //          continue;
       //      }
       //      else if((ba[i]==0 && bb[i]==1 &&carry ==0) || (ba[i]==1 && bb[i]==0 &&carry ==0)){
       //          ba[i] = 1 ;
       //      }
       //      else if(ba[i]==0 && bb[i]==0 &&carry ==1){
       //          ba[i]=1;
       //          carry=0;
       //      } 
       //  }
       //  int ans =0 ;
       // for(int i=0 ; i < 32 ; i++){
       //     ans = ans | (1 << i);
       // }             
       //  return ans;
        
    // }
            int getSum(int a, int b) {
if (b==0) return a;
	int sum = a^b; // finding the sum
	int carry = (unsigned int)(a & b)<<1; // finding the carry
	return getSum(sum, carry);
            }
};
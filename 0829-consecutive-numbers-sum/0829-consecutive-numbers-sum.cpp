class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // This has to be some maths behind it. 
        // Ref https://blog.gmatwhiz.com/2022/09/28/number-of-odd-even-factors/
        // So we see that odd factors contribute to the consecutive sum nature . 
        // Therefore odd^pow then it would contribute *(pow+1);
        // first remove power of 2;
        while(n%2==0) n/= 2 ;
        int ans = 1 ;
        for(int i=3 ; i<=n ; i+=2){
            int count = 0 ;
            while(n%i==0){
                n/=i ;
                count++ ;
            }
            ans = ans * (count+1); 
        }
        return ans ;
    }
};
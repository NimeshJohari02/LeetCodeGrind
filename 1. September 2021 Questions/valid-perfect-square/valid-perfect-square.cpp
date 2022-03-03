class Solution {
public:
    bool isPerfectSquare(int x) {
        long long int l =0;
     long long int r = x;
        long long int mid;
    // int ans =0;
        while(r>=l){
             mid = (l+r)/2;
            if((mid * mid) ==x){
                return true;
            }
            else if((mid*mid)<x){
                l=mid+1;
            }
            else{
                r=mid-1;

            }
        }
        return false;
    }
};
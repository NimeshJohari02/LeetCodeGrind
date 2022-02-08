class Solution {
public:
    int r(int n){
        if(n<10)
            return n;
        int s=0;
        while(n){
            s += n%10; 
            n /=10; 
        }
        return r(s);
    }
    int addDigits(int num) {
        return r(num);
    }
};
class Solution {
public:
 int singleNumber(vector<int>& s) {
        int a=0;
        int b=0;
        for(int c:s){
            int ta=(~a&b&c)|(a&~b&~c);
            b=(~a&~b&c)|(~a&b&~c);
            a=ta;
        }
        return a|b; 
 }
};
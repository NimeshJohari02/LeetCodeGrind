class Solution {
public:
    string largestOddNumber(string num) {
        //odd number is one that is not divisible by 2
        int s = num.size()-1;
        while( num.size()>0 && (num.back()-'0')%2==0 )num.pop_back();
        return num;
    }
};
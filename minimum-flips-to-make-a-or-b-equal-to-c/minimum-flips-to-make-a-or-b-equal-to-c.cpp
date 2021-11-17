class Solution {
public:
 
     int minFlips(int a, int b, int c) {
         //(a|b^c ) ke bits -> Denotes number of set bits that are different(XOR) in a| b and c . And a & b & diff would basically create that bits jisne c should be high and given both a and b are 0 then to accomodate that 
           return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & ((a | b) ^ c));
     }
};
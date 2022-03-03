class Solution {
public:
    string intToRoman(int num) 
    {
        // Ps not an interview Question . The  core logic is to find the bare minimum Roman number that are needed to generate
        // a valid roman number and then subtract it's value greedily 
        // For example 4 must be written as IV and not IIII thus store the correct value of 4 in that . 
        string res;
        string lookup[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for(int i=0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += lookup[i];
            }
        }
        
        return res;
    }
};
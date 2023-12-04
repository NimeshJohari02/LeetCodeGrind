class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // str1+str2 == str2+str1 iff gcd exists 

        /*
        Input: str1 = "ABABAB", str2 = "ABAB"
        Output: "AB"
        str1+str2 = ABABABABAB
        str2+str1 = ABABABABAB
        
        s = K.t;
        t;
        s+t = (K+1)t = t+s 
        */
        return (str1+str2==str2+str1) ? str1.substr(0, gcd(str1.size(),str2.size())): "";
    }
};


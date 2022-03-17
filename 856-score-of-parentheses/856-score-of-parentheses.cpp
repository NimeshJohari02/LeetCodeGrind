class Solution {
public:
    int scoreOfParentheses(string s) {
        int factor =0 , score = 0;
        for(int i=0 ; i < s.size() ; i++){
            if(s[i] =='('){
                factor++;
            }
            else{
                factor--;
                if(s[i-1] == '('){
                    score+= 1<< factor;
                }
            }
        }
        return score ; 
    }
};
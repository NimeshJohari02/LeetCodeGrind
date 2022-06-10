class Solution {
public:
    vector<string> ans;
    void helper(int open , int close , string &str ){
        if(open == 0 && close ==0){
            ans.push_back(str);
            return ;
        }
        if(open>0){
            str.push_back('(');
            helper(open-1 , close , str);
            str.pop_back();
        }
        if(close > open){
            str.push_back(')');
            helper(open , close-1 , str);
            str.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string str ="";
        helper(n , n , str);
        return ans;
    }
};
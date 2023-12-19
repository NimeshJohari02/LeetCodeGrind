class Solution {
public:
    vector<string>ans ;
    void rec(int open , int close , int n , string &miniAns){
        if(open==n && close == n){
            ans.push_back(miniAns);
            return ;    
        } 
        if(open < n ){
            miniAns.push_back('(');
            rec(open+1 , close , n , miniAns);
            miniAns.pop_back();
        }
        if(close < open){
            // open > close implies I can close a bracket here 
            miniAns.push_back(')');
            rec(open , close +1 , n , miniAns);
            miniAns.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string miniAns = "";
        rec(0 , 0 ,n , miniAns);
        return ans ;
    }
};
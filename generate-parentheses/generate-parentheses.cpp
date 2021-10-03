class Solution {
public:
    void solve(int open , int close , string out , vector<string>&v ){
    if(open == 0 and close ==0 ){
        v.push_back(out);
    }
    string ch1(out);
    string ch2(out);
    if(open !=0){
        ch1 += '(';
        solve(open - 1, close, ch1, v);

}
if(close>open){
            ch2 += ')';
            solve(open , close-1, ch2, v);
}
return;
}
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string op="";
        solve(n,n,op,v);
        return v;
        }
};
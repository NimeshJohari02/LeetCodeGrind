class Solution {
public:
    string naiveSolution(string &s){
        vector<int>open;
        string res = "";
        for(int i=0 ; i < s.size() ; i++){
            if(s[i] == '('){
                open.push_back(res.size());
            }
            else if(s[i]==')'){
                int j = open.back();open.pop_back();
                reverse(res.begin()+j, res.end());
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
    string reverseParentheses(string s) {
        //return naiveSolution(s);
        int n = s.size() ;
        vector<int>open , pair(n);   
        for(int i=0 ; i < s.size() ; i++){
            if(s[i] == '(') open.push_back(i);
            else if (s[i]==')') {
                int j= open.back();
                open.pop_back();
                pair[i] = j ;
                pair[j] = i;
            }
        }
        string ans = "";
        for(int i=0, d=1 ; i < n ; i+=d){
            if(s[i] == '(' || s[i] == ')'){
                i = pair[i] ;
                d = -d ;
            }
            else{
                ans+=s[i];
            }
        }
    return ans;
    }
};
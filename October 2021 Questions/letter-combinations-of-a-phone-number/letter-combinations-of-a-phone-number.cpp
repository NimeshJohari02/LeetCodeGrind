class Solution {
public:
void helper(string &ip , string op, int i , vector<string>&keypad,vector<string>&ans){
    if(ip[i]=='\0'){
        cout<<op<<endl;
        ans.push_back(op);
        return;
    }
    int digit = ip[i] - '0';
    if(digit==1||digit==0){
        helper(ip, op, i + 1 , keypad,ans);
    }
    for (int k = 0; keypad[digit][k]!='\0';k++){
        op.push_back(keypad[digit][k]);
        helper(ip, op, i + 1, keypad,ans);
        op.pop_back();
    }
        return;
}
vector<string> letterCombinations(string digits) {
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;  
        string op;
        helper(digits, op ,0, keypad,ans);
        if(digits==""){
            return {};
        }
            return ans ;
    }
};
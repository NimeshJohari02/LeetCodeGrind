class Solution {
public:
    vector<vector<string>>ans;
    bool isPallindrome(string s , int start , int end){
        while(end >= start)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
    void helper(int idx , string s , vector<string>&subString){
        if(idx == s.size()){
            ans.push_back(subString);
            return ;
        }
        for(int i =idx ; i <s.size() ; i++){
            if(isPallindrome(s , idx , i)){
                subString.push_back(s.substr(idx , i - idx +1));
                helper(i+1 , s , subString);
                subString.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>subString;
        helper(0 , s , subString);
        return ans;
    }
};
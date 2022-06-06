class Solution {
public:
    vector<vector<string>> ans;
    bool isPallindrome(string &str ,  int left , int right){
        while(right>=left)
            if(str[right--]!=str[left++]) return false;
        return true;
    }
    void helper(string mainString , int idx , vector<string>&ds ){
        if(idx == mainString.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i = idx  ; i <mainString.size() ; i++){
            if(isPallindrome(mainString , idx , i )){
                ds.push_back(mainString.substr(idx , i - idx +1 ));
                helper(mainString , i+1 , ds );
                ds.pop_back();
            }
        }
        return ;
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        helper(s , 0 , ds);
        return ans;
    }
};
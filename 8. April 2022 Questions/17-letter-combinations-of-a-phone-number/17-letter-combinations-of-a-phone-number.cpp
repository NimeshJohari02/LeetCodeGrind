class Solution {
public:
    vector<string>ans;
    void helper(int idx , string &ip , string &op  , vector<string>&arr){
        if(idx == ip.size()){
            ans.push_back(op);
        return ;
        }
        for(int i =0 ; i < arr[ip[idx]-'0'].size() ; i++){
            op.push_back(arr[ip[idx]-'0'][i]);
            helper(idx+1 , ip , op , arr);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
    vector<string> arr ={"" , "" , "abc","def","ghi" ,"jkl" , "mno" , "pqrs" ,"tuv" , "wxyz"};
        if(digits.size() ==0) return {};
        string op = "";
        helper(0 ,digits , op  ,  arr );
        return ans;
    }
};
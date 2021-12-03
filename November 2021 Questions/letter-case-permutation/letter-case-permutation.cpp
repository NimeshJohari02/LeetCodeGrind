class Solution {
public:
    vector<string>ans;
    void helper(string ip , string op){
        if(ip.empty()){
            ans.push_back(op);
            return;
        }
        string c1(op);
        string c2(op);
       if(isdigit(ip[0])){ 
            op.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            helper(ip,op); 
        }
        else{
           c2.push_back(toupper(ip[0]));
           c1.push_back(tolower(ip[0]));
        ip.erase(ip.begin()+0);
        helper(ip,c1);
        helper(ip,c2); 
        }

        return;
    }
    vector<string> letterCasePermutation(string s) {
        helper(s,"");
        return ans;
    }
};
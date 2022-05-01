class Solution {
public:

    string gs(string str){
        string ans ="";
        for(int i=0 ; i < str.size() ;i++){
            if(str[i]=='#'){
                if(!ans.empty())
                    ans.pop_back();
                else
                    ans="";
            }
            else{
                ans+=str[i];
            }
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return  gs(s)==gs(t);
    }
};
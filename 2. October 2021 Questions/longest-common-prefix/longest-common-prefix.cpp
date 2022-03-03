class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res ="";
        int i =0;
        for(;i<strs[0].length();i++){
             bool b = true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[0][i]){
                    b = false;
                    break;
                }
            }
         if (b) {
                res += strs[0][i];
            }
            else{
                break;
            }   
        }
        return res;
    }
};
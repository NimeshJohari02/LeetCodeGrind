class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans;
        int j=s.length()-1;
        int i=0;
        while(i<j){
            if(!isalpha(s[i])){
                i++;
            }
            if(!isalpha(s[j])){
                j--;
            }
            if(isalpha(s[i]) and isalpha(s[j])){
                cout<<s[i]<<s[j]<<endl;
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
               return s;
    }
};
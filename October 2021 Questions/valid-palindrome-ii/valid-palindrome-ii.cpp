class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        int counter =1;
        bool lflag = true;
        bool rflag = true;
        while(j>=i){
            if(s[i]!=s[j] and counter==0){
                lflag = false;
                break;
            }
            else if(s[i]!=s[j] and counter==1){
                counter--;
                j--;
            }
            else{
                i++;
                j--;
            }
        }
         j=s.length()-1;
         i=0;
        counter=1;
         while(j>=i){
            if(s[i]!=s[j] and counter==0){
                rflag = false;
                break;
            }
            else if(s[i]!=s[j] and counter==1){
                counter--;
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        return (rflag || lflag);
    }
};
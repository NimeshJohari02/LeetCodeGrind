class Solution {
public:
    bool checkZeroOnes(string s) {
        int count =0;
         int maxOnes =0;
    if(s.length()==1){
        if(s[0]=='1'){
            return true;
        }
        if(s[0]=='0'){
            return false;
        }
    }
     for(int i=0;i<s.length();i++){
         if(s[i]==s[i+1] and s[i]=='1'){
             count=0;
             while(s[i]=='1'){
                 count++;
                 i++;
             }
             maxOnes = max(count,maxOnes);
         }   
     }
        count=0;
         int maxZero =0;
        for(int i=0;i<s.length();i++){
         if(s[i]==s[i+1] and s[i]=='0'){
             count=0;
             while(s[i]=='0'){
                 count++;
                 i++;
             }
             maxZero = max(count,maxZero);
         }   
     }
        return maxOnes>maxZero;
    }
};
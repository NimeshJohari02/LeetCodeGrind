class Solution {
public:
    int lengthOfLastWord(string s) {        
        int ans = s.size()-1;
        if(s.size()==1) return 1;
        while(ans>=0 && s[ans]==' ')ans--;
        // now ans is at lastnonEmptyChar;
        int temp = 0 ;
        while(ans>=0&& s[ans--]!=' ')temp++;
        return temp;
        
    }
};
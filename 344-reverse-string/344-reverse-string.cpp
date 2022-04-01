class Solution {
public:
    void reverse(vector<char>&str, int left , int right){
        if(left>right){
           return ; 
        }
        swap(str[left],str[right]);
        return reverse(str,++left,--right);
    }
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
    }
};
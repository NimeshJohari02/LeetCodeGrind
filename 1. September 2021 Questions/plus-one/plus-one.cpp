class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        // int k=1
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=(carry);
            carry=0;
            if(digits[i]>=10){
                digits[i]-=10;
                carry=1;
            }
        }
        if(carry>0){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
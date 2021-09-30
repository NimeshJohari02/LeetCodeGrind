class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry =0;
        for(int i=num.size()-1;i>=0;i--){
            num[i]=num[i]+k%10+carry;
            // carry=0;
            carry = num[i]/10;
            if(num[i]>=10){
                carry=1;
                num[i]-=10;
            }
            k=k/10;
        }
        while(k) {
            num.insert(num.begin(), k%10 + carry);
            carry = num[0]/10;
            num[0] = num[0]%10; 

            k = k/10;
        }  
        if(carry>0){
            num.insert(num.begin(), carry);
        }
        return num;
    }
};
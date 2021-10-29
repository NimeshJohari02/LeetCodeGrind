class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int ans =0;
        int j=0;
        for(int i=columnTitle.length()-1;i>=0;i--){
            ans+=((columnTitle[i]-'A'+1)*pow(26,j));
            j++;
        }
        return ans;
    }
};
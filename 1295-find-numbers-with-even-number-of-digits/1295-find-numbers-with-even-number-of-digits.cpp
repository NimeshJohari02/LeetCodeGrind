class Solution {
public:
    int num_of_digit(int n){
        return floor(log10(n) + 1);
       }
    int findNumbers(vector<int>& nums) {
     int ans =0;
        for(auto &it : nums)
            if(num_of_digit(it)%2 ==0)
                ans++;
        return ans;
    }
};
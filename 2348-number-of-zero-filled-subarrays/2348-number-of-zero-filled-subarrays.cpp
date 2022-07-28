class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    long long ans = 0;
    int i=0 , j =0 ;
    while(i < nums.size()) {
        if (nums[i] != 0)
            j = i + 1;
         ans += i - j + 1;
        i++;
    }
    return ans;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int n = nums.size();
        int sum = (n*(n+1))/2;
        n = 0 ;
        for(auto&it:nums)n+=it;
        return sum - n ;
    }
};
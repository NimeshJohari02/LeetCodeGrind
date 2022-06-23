class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (auto &it : nums)
        if ( i==0 || it > nums[i-1])
            nums[i++] = it;
    return i;
    }
};
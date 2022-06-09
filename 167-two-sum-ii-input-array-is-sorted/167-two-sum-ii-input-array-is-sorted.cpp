class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        while(end>=start){
            int cs = nums[start]+nums[end];
            if(target==cs){
                return {start+1,end+1};
            }
            else if (target>cs){
                start++;
            }
            else{
                end--;
            }
        }
        return {-1,-1};
    }
};
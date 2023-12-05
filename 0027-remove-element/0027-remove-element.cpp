class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int currIdx = 0 , i=0 ;
        for(; i < nums.size() ;i++){
            if(nums[i]!=val){
                nums[currIdx++] = nums[i];
            }
        }
        return currIdx ;
    }
};
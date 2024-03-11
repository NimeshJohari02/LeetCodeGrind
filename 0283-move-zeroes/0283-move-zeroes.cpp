class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currIdx = 0 ;
        // Since we have to preserve the order the swap mechanism would fail to succeed . 
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]!=0){
                nums[currIdx++] = nums[i];
            }
        }
        for(int i = currIdx; i < nums.size() ; i++)nums[i]  =0 ;
    }
};
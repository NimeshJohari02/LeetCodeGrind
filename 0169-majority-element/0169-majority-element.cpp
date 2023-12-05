class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentMajorityElement = nums[0]; 
        int count = 1;
        for(int i=1 ; i < nums.size() ; i++){
            if(count == 0) currentMajorityElement = nums[i], count = 1 ;
            else if(nums[i]==currentMajorityElement) count++;
            else count--;
        }
    return currentMajorityElement;
    }
};
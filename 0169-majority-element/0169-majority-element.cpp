class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentMajorityElement = INT_MAX; 
        int count = 0;
        for(int i=0 ; i < nums.size() ; i++){
            if(count == 0) currentMajorityElement = nums[i], count = 1 ;
            else if(nums[i]==currentMajorityElement) count++;
            else count--;
        }
    return currentMajorityElement;
    }
};
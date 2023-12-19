class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0 , j = nums.size()-1 ;
        while(j>=i){
            int currSum = (nums[i]+nums[j]);
            if(currSum == target)return {i+1 , j+1};
            else if(currSum > target) j--;
            else i++;
        }
    return {-1 , -1};
    }    
};
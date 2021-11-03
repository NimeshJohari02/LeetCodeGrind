class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]-nums[i-1] != nums[i+1]-nums[i]){
                return false;
            }
        }
        return true;
    }
};
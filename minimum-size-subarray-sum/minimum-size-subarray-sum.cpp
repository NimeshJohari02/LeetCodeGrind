class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left = 0, right = 0, len = nums.size(), sum = 0;
        
        for(int right = 0, left = 0; right < len; right++){
            sum += nums[right];
            
            while(sum >= target){
                minLen = min(minLen, (right-left+1));
                sum -= nums[left];
                left++;
            }
        }
        return minLen != INT_MAX ? minLen : 0;
    }
};
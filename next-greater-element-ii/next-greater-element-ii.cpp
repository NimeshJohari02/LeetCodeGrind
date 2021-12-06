class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> stk; 
        for(int i=nums.size()-1; i >= 0;i--) {
            stk.push(nums[i]);
        }

        for(int i = nums.size()-1; i>=0;i--) {
            while(!stk.empty()) {
                if(stk.top()>nums[i]) break;
                stk.pop();
            }
            ans[i] = stk.empty()?-1:stk.top();
            stk.push(nums[i]);
        }

        return ans;
    }
};
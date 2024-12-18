class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
     // next smallest element will be discount (NSR Stack) . 
        vector<int>ans(nums.size() , 0);
        stack<int>stk ;
         for(int i = nums.size()-1; i>=0;i--) {
            while(!stk.empty()) {
                if(stk.top()<=nums[i]) break;
                stk.pop();
            }
            ans[i] = stk.empty()?nums[i]:nums[i]-stk.top();
            stk.push(nums[i]);
        }
        return ans ;
    }
};

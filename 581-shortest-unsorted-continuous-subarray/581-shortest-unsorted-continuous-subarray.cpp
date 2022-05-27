class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n ;
        int r =0;
        stack<int>stk;
        // max idx for nearest greatest rigth
        for(int i = n-1 ; i>=0 ; i--){
            while(!stk.empty() && nums[stk.top()]  < nums[i]){
                r = max(r , stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        stk = stack<int>();
        // minimum idx for the nearest smallest to the left  ka idx
        for(int i=0 ; i < n ; i++)
        {
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                l = min(l , stk.top());
                stk.pop();
            }
            stk.push(i);
        }
    
    return r-l > 0 ? r-l+1 : 0 ;
    }
};
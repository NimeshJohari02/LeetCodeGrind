class Solution {
public:
    vector<int>nsl(vector<int>&height){
        int n = height.size();
        vector<int>ans(n , 0);
        stack<int>stk;
        for(int i=0 ; i < n ; i++)
        {
            while(!stk.empty() && height[stk.top()] >= height[i])stk.pop();
            if(stk.empty()) ans[i]= 0;
            else ans[i] = stk.top()+1;
            stk.push(i);
        }
        return ans ; 
    }
    vector<int>nsr(vector<int>&height){
         int n = height.size();
        vector<int>ans(n , 0);
        stack<int>stk;
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(!stk.empty() && height[stk.top()] >= height[i])stk.pop();
            if(stk.empty()) ans[i]= n-1;
            else ans[i] = stk.top()-1;
            stk.push(i);
        }
        return ans ;   
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left = nsl(heights);
        vector<int>right = nsr(heights);
        int ans = 0 ;
        for(int i=0 ; i < heights.size();i++)
            ans = max(ans , (right[i]-left[i]+1)*heights[i]);
        return ans ; 
    }
};
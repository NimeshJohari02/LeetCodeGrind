class Solution {
public:
    vector<int>getNSL(vector<int>&heights ){
        vector<int>ans;
        int pseudoIdx =-1;
        stack<pair<int,int>>stk;
        for(int i =0 ; i<heights.size(); i++){
            if(stk.empty()){
                ans.push_back(pseudoIdx);
            }
            else if(heights[i]> stk.top().first){
                ans.push_back(stk.top().second);
            }
            else if(!stk.empty() and heights[i]<=stk.top().first){
                while(!stk.empty() and heights[i]<=stk.top().first){
                    stk.pop();
                }
                if(stk.empty()){
                    ans.push_back(pseudoIdx);
                }
                else{
                    ans.push_back(stk.top().second);
                }
            }
            stk.push({heights[i],i});
        }
        return ans;
    }
    vector<int> getNSR(vector<int>&height){
        vector<int>ans;
        stack<pair<int,int>>stk;
        int pseudoIdx = height.size();
        for(int i= height.size()-1 ; i>=0 ; i--){
            if(stk.empty())
                ans.push_back(pseudoIdx);
            else if(height[i]>stk.top().first){
                ans.push_back(stk.top().second);
            }
            else if(!stk.empty() and height[i]<=stk.top().first){
                while(!stk.empty() and height[i]<=stk.top().first){
                    stk.pop();
                }
                if(stk.empty()){
                    ans.push_back(pseudoIdx);
                }
                else{
                    ans.push_back(stk.top().second);
                }
            }
            stk.push({height[i],i});
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
         vector<int> NSL = getNSL(heights );
        vector<int> NSR = getNSR(heights );
        int n = heights.size();
        int maxAr=INT_MIN;
        for(int i=0;i<n;i++){
                int area = (NSR[i]-NSL[i]-1)*heights[i];
                maxAr= max(maxAr,area);
        }
        return maxAr;
    }
};




class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size(), area = 0;
        stack<int> indexes;
        for (int i = 0; i < n; i++) {
            while (!indexes.empty() && height[indexes.top()] > height[i]) {
                int h = height[indexes.top()]; indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - l - 1));
            }
            indexes.push(i);
        }
        return area; 
    }
};

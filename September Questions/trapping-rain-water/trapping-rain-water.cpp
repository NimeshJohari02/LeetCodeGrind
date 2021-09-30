class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftMax;  
        vector<int>rightMax(height.size());  
      int left=INT_MIN;
        int right = INT_MIN;
        for(int i=0;i<height.size();i++)
        {
          left=max(left,height[i]);
          right=max(right,height[height.size()-i-1]);
          leftMax.push_back(left);
          rightMax[height.size()-i-1]=right;
        }
      int ans =0;
      for(int i=0;i<height.size();i++){
        ans+=(min(leftMax[i],rightMax[i])-height[i]);
      }
      return ans;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
    int ans = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int minHeight = min(height[i], height[j]);
        ans = max(ans, (j - i) * minHeight);
        while (height[i] <= minHeight && i < j) i++;
        while (height[j] <= minHeight && i < j) j--;
    }
    return ans;
    }
};

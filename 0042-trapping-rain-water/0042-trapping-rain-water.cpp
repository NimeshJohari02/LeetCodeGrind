class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n,0 ) , right(n , 0);
        for(int i=0;i<height.size();i++)
            left[i]=i==0?height[0]:max(height[i] , left[i-1]);
        for(int i=n-1;i>=0;i--)
            right[i]=(i==n-1)?height[i]:max(height[i] , right[i+1]);
        int ans= 0 ;
        for(int i=0 ; i < n ; i++)
            ans += (min(left[i], right[i]) - height[i]);
        return ans ; 
    }
};
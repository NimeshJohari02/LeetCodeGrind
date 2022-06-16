class Solution {
public:
    int bruteForce(vector<int>&nums){
                int ans = 0 ;
        for(int i=0 ; i  < nums.size() ; i++)
            for(int j = nums.size() -1 ; j>=i ; j--)
                if(nums[j]>=nums[i])
                    ans = max(ans , j-i);
        return ans;
    }
    
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMin(n , 0) , rightMax(n , 0);
        for(int i=0 ; i < n ; i++)
            leftMin[i] = i==0 ? nums[i] : min(nums[i] , leftMin[i-1]);
        for(int i=n-1 ; i >= 0 ; i--)
            rightMax[i] = i==n-1 ? nums[i] : max(nums[i] , rightMax[i+1]);
        int l=0 , r=0  , ans=0;
        while(l < n && r < n){
            if(rightMax[r]>=leftMin[l])r++;
            else l++;
            ans =max(ans , r-l-1);
        }
        return ans;
        
    }
};
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0 || n==1)return n ;
        // Brute Force ;
        vector<int>nums(n+1, 0 );
        int ans = 0 ;
        nums[0] = 0 ;
        nums[1] = 1;
        for(int i=2 ; i <= n ; i++)
        {
            if(i%2!=0){
                nums[i] = nums[i/2]+ nums[(i+1)/2];
            }
            else{
                nums[i] = nums[i/2];
            }
            ans = max(ans , nums[i]);
        }
        // for(auto&it : nums)
        //     cout<<it<<"  ";
        
        return ans;
    }
};
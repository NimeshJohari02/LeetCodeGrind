class Solution {
public:
    // longest subarry of sum = x nikaal du 
    int minOperations(vector<int>& nums, int x) {
        int left=0 , right=0 , n = nums.size() , ans = INT_MAX;
        int sum =0;
        for(auto it : nums)
            sum+=it;
        while(right>=left){
            if(sum>=x){
                if(sum == x){
                    ans = min(ans , left+n-right);
                }
                
                if(right<n)
                    sum-=nums[right++];
                else 
                    break;
            }else{
                sum+=nums[left++];
            }
        }
           return ans == INT_MAX ? -1 : ans; 
    }
};
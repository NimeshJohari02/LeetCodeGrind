class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long  i=0 , j=0 , ans =0 , cs =0 ;
        for( int  j=0 ; j < nums.size() ; j++){
            cs +=nums[j];
            // long long score = cs * (j-i+1);
            // Value of score not updated in while loop
            while(cs * (j-i+1) >= k){
                cs-=nums[i];
                i++;
            }
            ans += (j-i+1);
        }
        return ans;
    }
};
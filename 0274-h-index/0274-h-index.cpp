class Solution {
public:
    bool isPossibleHIndex(int idx , vector<int>&nums){
        int count=0;
        for(auto &it : nums)
            if(it>=idx)count++;
        return count>=idx;
    }
    int hIndex(vector<int>& nums) {
        // if h-index is K . Then number of values in the array >=k should be greater than equal to K.
        int end = *max_element(nums.begin() , nums.end());
        int start = 0,ans = 0 ;
        while(end >= start){
            int mid = (start+end)>>1;
            if(isPossibleHIndex(mid , nums))ans = max(ans , mid), start = mid+1 ;
            else 
                end=mid-1;
        }
        return ans ;
    }
};
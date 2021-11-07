class Solution {
public:
        int atmostKDifferent(vector<int>&nums , int k ){
         int i=0 , cnt =0;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int j = 0 ; j< n ; j++){
            mp[nums[j]]++;
            while(mp.size() > k ){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt += j-i+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostKDifferent(nums , k )- atmostKDifferent(nums , k-1);
    }
};
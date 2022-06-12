class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // maximum subarray sum with unique elements 
        //Unique Elements => unordered_set.size()==j-i+1
        int i =0 ,j =0 , sum =0  , ans = 0 ;
        unordered_map<int,int> mp;
        for(int j=0 ; j < nums.size() ; j++){
            mp[nums[j]]++;
            sum+=nums[j];
            if(mp.size() == j-i+1){
                ans = max(ans , sum);
            }
            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    sum-=nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)mp.erase(nums[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};
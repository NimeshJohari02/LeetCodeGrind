class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int total = accumulate(nums.begin() , nums.end() , 0);
        if(k==nums.size())return total;
        int cs = accumulate(nums.begin() , nums.end()-k , 0);
        int ans = total - cs;
        for(int i=0 , j = nums.size() - k; j < nums.size() ; j++ , i++){
            ans=max(ans ,  total - (cs += nums[j]-nums[i]));
        }
        return ans;
    }
};

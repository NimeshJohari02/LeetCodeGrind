class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0){
            map<int,int>mp;
            for(auto&it:nums)
                mp[it]++;
            int ans =0;
            for(auto &it:mp)
                if(it.second>=2)
                    ans++;
            return ans;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        int count =0;
        int n = nums.size();
        for(int i=0 ; i <n ; i++ ){
            int ch1= k+nums[i];
            int ch2 = nums[i]-k;
            if(mp[ch1]>0){
                count++;
                mp[ch1]--;
            }
             if(mp[ch2]>0){
                count++;
                mp[ch2]--;
            }
            mp[nums[i]]=1;
        }
        return count;
        
    }
};
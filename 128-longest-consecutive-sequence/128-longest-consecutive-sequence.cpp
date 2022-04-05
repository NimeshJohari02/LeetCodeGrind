class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_map<int , int> mp;
        if(nums.size() ==0) return 0;
        for(auto &it : nums) mp[it]++;
        int ls = 1;
        for(int i=0 ; i < nums.size() ; i++){
         int curr = nums[i];
            if(mp[curr-1]==0){
                int modNum = curr;
                int cs = 1;
                while(mp[modNum+1] >0){
                    modNum+=1;
                    cs++;
                }
                ls = max (ls , cs);
            }
        }
        return ls;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       // nums of element whose sum = k;
        map<int, int> mp;
        int cnt = 0;
        for(auto it : nums)
        {
            if(mp[k-it]){
                cnt += 1;
                mp[k-it]--;
            }else mp[it]++;
            
        }
  return cnt;
    }
};
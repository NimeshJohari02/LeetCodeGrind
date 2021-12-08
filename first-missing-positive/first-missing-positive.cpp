/*class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        map<int,int>mp;
        int maxm = INT_MIN;
        for(auto&it:arr){
        mp[it]++;
            maxm=max(maxm, it);
        }
        if(maxm <=0)
            return 1;
        for(int i =1 ; i<=maxm;i++){
            if(mp[i]==0)
                return i;
        }
        return maxm+1;
        }
};*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
               for(int i = 0; i < n; ++ i)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(nums[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};
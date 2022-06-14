class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
     // max element nikaal ke 
        // vector<int>ans;
        int idx = 0;
        int occ=0;
        for(int i=0 ; i < nums.size() ; i++){
            if(nums[i]==target)occ++;
            else if(nums[i]< target) idx++;
        }
        vector<int>ans(occ , 0);
        for(int i=0 ; i < ans.size();i++)
            ans[i] +=idx+i;
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() ,nums.end());
        vector<vector<int>> ans;
        for(int i=0 ; i < nums.size() ; i++){
            int target = -nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(end >start){
                if(nums[start] + nums[end] > target)
                    end--;
                else if (nums[start] + nums[end] < target) 
                    start++;
                else if(nums[start]+ nums[end] == target){
                    vector<int> ansCandidate = {nums[i] , nums[start] , nums[end]};
                    ans.push_back(ansCandidate);
                    while(end > start and nums[start] == ansCandidate[1] )start++;
                    while(end > start and nums[end] == ansCandidate[2] )end--;
                }
            }
            while(i+1<nums.size() && nums[i] == nums[i+1])i++;
        }
        return ans;
    }
};
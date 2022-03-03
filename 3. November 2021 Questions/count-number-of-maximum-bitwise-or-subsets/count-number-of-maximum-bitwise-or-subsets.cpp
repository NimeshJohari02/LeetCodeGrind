class Solution {
public:
    int maxOr =0;
    int cnt =0;
    void findMax(vector<int> &nums, vector<int>&subset, int index , int currentOr){
        if(currentOr == maxOr) cnt++;
        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            findMax(nums, subset, i+1,currentOr | nums[i]);
            subset.pop_back();
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<int>arr;
        for(auto it : nums){
            maxOr = maxOr | it ;
        }
        findMax(nums , arr,0,0);
        return cnt;
    }
};
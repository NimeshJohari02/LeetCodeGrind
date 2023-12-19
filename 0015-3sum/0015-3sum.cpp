class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the array and use one loop and 2 pointers
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans ;
        for(int i=0 ; i < nums.size();i++){
            int modifiedTarget = -nums[i];
            int j = i+1,k = n-1;
            while(k>j){
                int currSum = nums[k]+nums[j];
                if(currSum>modifiedTarget)k--;
                else if(currSum < modifiedTarget)j++;
                else{
                    vector<int>miniAns = {nums[i],nums[j],nums[k]};
                    ans.push_back(miniAns);
                    while(k > j && nums[j]==miniAns[1])j++;
                    while(k > j && nums[k]==miniAns[2])k--;
                }
                while(i+1<n && nums[i]==nums[i+1])i++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size();i++){
            int target  = -nums[i];
            int front = i+1;
            int back = nums.size()-1;
            while(back>front){
                int sum = (nums[front]+nums[back]);
                if(sum > target){
                    back--;
                }
                else if(sum < target){
                    front ++;
                }
                else{
                    vector <int> ansCandidate= {nums[i],nums[front],nums[back]};
                    ans.push_back(ansCandidate);
                    while(back > front and nums[front]==ansCandidate[1])
                        front++;
                    while(back > front and nums[back]==ansCandidate[2])
                        back--;
                }
            }
            while(i+1<nums.size() and nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};
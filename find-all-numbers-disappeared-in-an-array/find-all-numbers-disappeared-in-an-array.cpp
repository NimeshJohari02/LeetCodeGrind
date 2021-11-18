class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int correctIdx=nums[i]-1;
            if(nums[correctIdx]!=nums[i]){
                swap(nums[correctIdx],nums[i]);
            }
       else{
           i++;
       }  
        }
         vector<int>ans;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]!=i+1){
                    ans.push_back(i+1);
                }
            }
            if(nums.back()!=nums.size()){
                ans.push_back(nums.size());
            }
        return ans;
    }
};
class Solution {
public:
    // int ans = 0 ;
    // void helper(int idx , bool is_prev_diff_positive ,vector<int>&ds,  vector<int>&nums){
    //     if(idx == nums.size()){
    //         // int miniAns 
    //         ans = max(ans ,(int) ds.size());
    //         return ;
    //     }
    //     //pick and not pick based on difference
    //     // for pick
    //     if(ds.empty() ||  nums[idx] - ds.back() < 0 && is_prev_diff_positive ||  nums[idx] - ds.back() > 0 && !is_prev_diff_positive){
    //         ds.push_back(nums[idx]);
    //         helper(idx+1 , !is_prev_diff_positive , ds , nums);
    //         ds.pop_back();
    //         is_prev_diff_positive = !is_prev_diff_positive ;
    //     }
    //     //not pick 
    //     else helper(idx+1 , is_prev_diff_positive , ds , nums);
    //     return ;
    // }
    int wiggleMaxLength(vector<int>& nums) {
        // counting the number of peaks and valleys 
        int up = 1 , down = 1 , n = nums.size() ;
        for(int i=1 ; i < n ; i++){
            if(nums[i] > nums[i-1]) down = 1+up;
            else if(nums[i] < nums[i-1]) up = 1+down;
        }
        return max(up , down);
    }
};
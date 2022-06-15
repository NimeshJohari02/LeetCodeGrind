class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int n = nums.size() , idx1 , idx2 ;
        for(int i=n-2 ; i>=0 ; i--)
            if(nums[i+1] > nums[i]) {
                idx1 = i ;
                break;
            }
        if(idx1<0){
            // we have been given last permutaion ie 321 so reverse that and done ;
            reverse(nums.begin() , nums.end());
        }
        else{
            // now find idx2 such that nums[idx2] > nums[idx1]
            for(int j = n-1 ; j>idx1 ; j--)
                if(nums[j] > nums[idx1]){
                    idx2 = j;
                    break;
                }
            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin()+idx1+1 , nums.end());
        }
    return ;
    }
};
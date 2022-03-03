class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count =0;
        int j =0 ;
        int n = nums.size();
        if(n <3) return 0;
        for(int i=2 ; i < nums.size() ; i++){
            if((nums[i]- nums[i-1]) == (nums[i-1] - nums[i-2])){
                j++;
                count+=j;
            }
            else{
                j=0;
            }
        }
        return count ;
    }
};
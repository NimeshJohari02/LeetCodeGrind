class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
     int n = nums.size();
        int oddIdx =1;
        int evenIdx=0;
        for(int i=0;i<n;i++){
         if(i%2==0 and nums[i]%2!=0){
             swap(nums[i],nums[oddIdx]);
             oddIdx+=2;
             i--;
         }
         else if(i%2!=0 and nums[i]%2==0){
             swap(nums[i],nums[evenIdx]);
             evenIdx+=2;
            i--;
         }
     }
        return nums;
    }
};
class Solution {
public:
    static bool cmp(int &a , int &b){
        return a %2 < b % 2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        // sort(nums.begin() , nums.end() , cmp);
        int i =0 ,  j = nums.size() -1 ;
        
      while(i <=j ){
            if(nums[i] %2 ==0 ) {i++;continue;}
            if(nums[j] %2!=0) {j-- ; continue;}
            if(nums[i] %2 != 0 && nums[j]%2 ==0 ){
                swap(nums[i],nums[j]) ;
                i++;
                j--;
            }
      }
        return nums;
    }
};
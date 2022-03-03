class Solution {
    private :
    int bruteForce(vector<int>&nums){    
        int back = nums.size()-1;
        int prev = nums[0];
        int countPrev =1 ;
        int converted =0;
        for(int i=1 ; i < nums.size() ; i++){
            if(nums[i]==prev){
                countPrev++;
                if(countPrev>2){
                    nums[i]=INT_MAX;
                    converted++;
                }
            }
            else{
                prev = nums[i];
                countPrev=1;
            }
        }
        sort(nums.begin() , nums.end());
        return nums.size() - converted ;
    }
    int optimized(vector<int>&nums ){
    int lastUsedIdx = 1, i = 1;
            int countPrev = 1;
            while (i < nums.size()) {
                if (nums[i] != nums[i-1]) {
                    countPrev = 1;
                    nums[lastUsedIdx++] = nums[i];
                }
                else {
                    if (countPrev < 2) {
                        nums[lastUsedIdx++] = nums[i];
                        countPrev++;
                    }
                }
                i++;
            }
            return lastUsedIdx;
    }
    public:
    
    int removeDuplicates(vector<int>& nums) {
        return optimized(nums);
    }
};
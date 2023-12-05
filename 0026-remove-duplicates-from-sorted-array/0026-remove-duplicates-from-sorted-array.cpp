class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int currIdx = 0 , i =0 ;
        if(nums.size()==1)return 1;
        while(i <= nums.size()-1)
        { 
            if(i==nums.size()-1) {
                if( nums[currIdx-1]==nums.back()) break;
                else {
                    nums[currIdx++] = nums.back();
                    i++;
                }
            }
            else
            {
            while(i < nums.size()-1 && nums[i]==nums[i+1] )i++;
            nums[currIdx++] = nums[i++];
            }
        }
     return currIdx;   
    }
};
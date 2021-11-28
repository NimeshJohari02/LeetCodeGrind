class Solution {
public:
    int binarySearch(vector<int>&nums , int start , int end ){
        while(end >=start){
            int midIdx = start + (end - start)/2;
            if(nums[midIdx]>nums[midIdx+1] and nums[midIdx-1]<nums[midIdx]){
             return midIdx;   
            }
            else if(nums[midIdx]<nums[midIdx+1]){
                start = midIdx+1;
            }
            else{
                end = midIdx-1;
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(), INT_MIN);
        int num = binarySearch(nums ,0 , nums.size()-1);
        if(num ==0 || num == nums.size()-1)
            return -1;
        return num-1;
    }
};
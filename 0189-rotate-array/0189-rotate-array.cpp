class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ,  rotationFactor = abs(n-k % n) ;
        for(int i=0 ; i < rotationFactor;i++)
            nums.push_back(nums[i]);
        // Now array is like 1,2,3,4,5,6,7,1,2,3,4
        // 1 2 3 --> 
        // Now resize the array start from rotationFactor and till nums.back();
        nums.erase(nums.begin() , nums.begin() + rotationFactor);
        return ; 
    }
};
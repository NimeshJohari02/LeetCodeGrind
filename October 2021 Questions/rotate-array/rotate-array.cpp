class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int secondAns = abs(n-k%n);
        for(int i = 0; i < secondAns; i++){
            nums.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            nums[i] = nums[i +secondAns ];
        }
        while(secondAns--){
            nums.pop_back();
        }
    }
};
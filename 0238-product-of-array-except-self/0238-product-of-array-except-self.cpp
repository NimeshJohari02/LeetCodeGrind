class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int leftProduct = 1;
        int rightProduct = 1;
        vector<int> ans(n, 1);
        /*
        [1,2,3,4]
        Output: [24,12,8,6]
        Approach Corner Cases mai ans[0] = rigtProduct of entire array and 
        ans[n-1] = leftProdct of entire arr
        for middle elements 
        
        we need to multiply from left -> num-1 and num+1 -->right 
        */
        for (int i = 0; i < n; i++) {
            // multuply so that ans[0] is mul by 1 and hence no effect 
            ans[i] = ans[i] * leftProduct;
            leftProduct = leftProduct * nums[i];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            // multuply so that ans[n-1] is mul by 1 and hence no effect 
            ans[i] = ans[i] * rightProduct;
            rightProduct =rightProduct * nums[i];
        }
        return ans;
    }
};
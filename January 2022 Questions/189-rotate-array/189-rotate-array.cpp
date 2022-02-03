class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       /* int n = nums.size();
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
        
        */
        
//Solution According to Hint II
        int n = nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k%n);
    reverse(nums.begin()+k%n,nums.end());
    }
    
    
};
class Solution {
public:
    int jump(vector<int>& nums) {
    int ans =0 , reach =0 , end =0;
        for(int i=0 ; i< nums.size()-1;i++){
            reach = max(reach,i+nums[i]);
            if(i== end){
                ans++;
                end = reach;
            }
        }
    return ans;
    }
};
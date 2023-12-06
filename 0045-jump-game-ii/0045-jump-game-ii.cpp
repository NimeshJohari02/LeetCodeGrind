class Solution {
public:

    int jump(vector<int>& nums) {
        int ans = 0 ,  end = 0 , maxReach = 0 ;
        //Since it is already said that we can reach the last element we need not consider the jump last element provides We need to reach last element not jump from last element also. So reduce the size of the array by 1 . 
        for(int i=0 ; i < nums.size()-1; i++){
            maxReach = max(maxReach , i + nums[i]);
            if(i==end){
                ans++ ;
                end = maxReach ;
            }
        }
        return ans ; 
    }
};
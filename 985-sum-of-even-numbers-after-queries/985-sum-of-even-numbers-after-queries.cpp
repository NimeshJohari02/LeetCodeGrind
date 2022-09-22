class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int currEvenSum = 0 ;
        vector<int>ans;
        for(auto &it : nums) if(it%2==0 ) currEvenSum+=it;
        for(auto &it : q){
            int init = nums[it[1]] ;
            int added = it[0];
            if(init%2==0 && (init+added)%2!=0) currEvenSum-=init , nums[it[1]]+=added ;
            if(init%2==0 && (init+added)%2==0) currEvenSum+=added , nums[it[1]]+=added ;
            if(init%2!=0 && (init+added)%2==0) currEvenSum+=added+init , nums[it[1]]+=added ;
            if(init%2!=0 && (init+added)%2!=0) nums[it[1]]+=added ;
            ans.push_back(currEvenSum);
        }
        return ans;
    }
};
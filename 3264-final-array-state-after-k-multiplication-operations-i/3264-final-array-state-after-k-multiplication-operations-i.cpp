class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
        for(int i=0 ; i < nums.size() ; i++)
            pq.push({nums[i] , i });
        while(k--){
            auto top = pq.top() ;
            pq.pop();
            int number = top.first;
            int index = top.second ; 
            pq.push({number * multiplier , index});
        }
        int n = nums.size();
        vector<int>ans(n , 0);
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            ans[node.second]  = node.first;
        }
        return ans ; 
    }
};
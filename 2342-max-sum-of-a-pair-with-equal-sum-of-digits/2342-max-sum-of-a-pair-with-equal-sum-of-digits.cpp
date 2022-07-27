class Solution {
public:
    int sum(int n){
        int ans = 0;
        while(n>0){
            ans += (n % 10);
            n/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int , int> mp;
        priority_queue<pair<int , int>> pq ;
        for(auto it : nums){
            int sum_of_digit = sum(it); 
            pq.push({sum_of_digit , it});
        }
        int ans = INT_MIN;
        while(!pq.empty()){
            auto node1 = pq.top();
            pq.pop();
            if(!pq.empty()){
                auto node2= pq.top();
                pq.pop();
                if(node1.first == node2.first) {
                    ans = max(ans , node1.second + node2.second);
                }
                else{
                    pq.push(node2);
                }
                }
        }
        return ans==INT_MIN ? -1 : ans;
    }
};
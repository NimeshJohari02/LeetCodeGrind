class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> pq;
        for(auto &it : nums)
            pq.push(it);
        while(k-- && !pq.empty()){
            int top = pq.top();
            pq.pop();
            pq.push(top+1);
        }
        long long int ans = 1;
        long long int mod = (int) 1e9+7;
        while(!pq.empty()){
            ans = ans * pq.top() % mod;
            pq.pop();
        }
        return ans;
    }
};
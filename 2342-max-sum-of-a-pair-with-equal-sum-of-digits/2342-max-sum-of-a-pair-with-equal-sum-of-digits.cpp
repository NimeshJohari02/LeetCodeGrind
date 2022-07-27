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
/*
int maximumSum(vector<int>& nums) {
    in this the max we could take is 10^5  ie when we have all 9's the sum would be 9 *9 = 81 thus take 82 to prevent overflow . 
    int res = -1, d_n[82] = {}; // 9 * 9
    for (int n : nums) {
        int d = 0;
        for (int nn = n; nn; nn /= 10)
            d += nn % 10;
        if (d_n[d])
            res = max(res, d_n[d] + n);
        d_n[d] = max(d_n[d], n);
    }
    return res;
}



*/
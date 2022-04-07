class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     priority_queue<int> pq;
        if(size(stones) == 1) return stones[0];
        for(auto &it : stones) pq.push(it);
        while(pq.size()!=1){
            int y = pq.top();
            pq.pop();
            int x = pq.empty() ? 0 : pq.top();
            pq.pop();
            if(y-x >=0) pq.push(y-x);
        }
        return pq.top();
    }
};
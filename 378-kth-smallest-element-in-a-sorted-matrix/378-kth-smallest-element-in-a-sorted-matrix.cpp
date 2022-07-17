class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        // kth smallest k 
        priority_queue<int> pq ;
        for(auto &it : m){
            for(auto &iit : it){
                pq.push(iit);
                if(pq.size() > k)pq.pop();
            }
        }
        return pq.top();
    }
};
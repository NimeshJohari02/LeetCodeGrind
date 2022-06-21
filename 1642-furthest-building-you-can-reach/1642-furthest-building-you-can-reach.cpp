class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        priority_queue<int> pq ;
        int i=0  , n = arr.size();
        for(; i < n-1; i++){
            int diff = arr[i+1] - arr[i];
            if(diff < 0) continue ;
            pq.push(-diff);
            if(pq.size() > ladders){
                // Already -ve as we pushed needed into the pq
                bricks += pq.top()  ;
                pq.pop();
            }
            if(bricks <0) return i ;
        }
        return i;
    }
};
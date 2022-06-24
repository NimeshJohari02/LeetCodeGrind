class Solution {
public:
    bool isPossible(vector<int>& arr) {
        long long int cs = 0 ;
        priority_queue<long long int> pq ;
        for(auto &it : arr){
            pq.push(it);
            cs+=it;
        }
        if(arr.size()==1) return arr[0] == 1;
        while(pq.top()!=1){
            long long int maxi = pq.top() ; pq.pop();
            long long int val = cs - maxi;
            if(val >=maxi) return false;
            long long int largestRem = (maxi - (maxi-1)/ val * val );
            pq.push(largestRem);
            cs = val + largestRem;
        }
        return true; 
    }
};
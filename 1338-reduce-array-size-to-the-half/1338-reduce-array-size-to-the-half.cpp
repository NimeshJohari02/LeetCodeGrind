class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto &it : arr)
            mp[it]++;
        int size= arr.size();
        // occurance , number
        priority_queue<pair<int , int>> pq;
        for(auto &it : arr){
            pq.push({mp[it] , it});
        }
        int ans =0 ;
        while(size > arr.size() /2){
            int currDelete = pq.top().first ;
            int currElement = pq.top().second;
            while(currElement == pq.top().second && !pq.empty())
                pq.pop();
            size-=currDelete ;
            ans++;
        }
        return ans;
    }
};
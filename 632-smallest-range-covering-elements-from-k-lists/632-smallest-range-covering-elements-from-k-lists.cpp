// class Solution {
// public:
//     // isSmaller returns true means p1 is smaller than p2 
//      bool isSmaller(pair<int,int>&p1 ,pair<int,int>&p2){
//              int d1 =p1.second-p1.first ;
//              int d2 = p2.second - p2.first ;
//              return d1 == d2 ? p2.second > p1.second : d1 < d2;
//          }
//     vector<pair<int ,int>> mergeIntoOne(vector<vector<int>>&nums){
//         vector<pair<int, int>> v;
//         int n = nums.size();
//         priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq ;
//         for(int i=0 ; i < nums.size() ; i++){
//             for(int j=0 ; j < nums[i].size() ; j++)
//                 pq.push({nums[i][j] , i});
//         }
//         while(!pq.empty())
//         {
//             v.push_back(pq.top());
//             pq.pop();
//         }
//         return v;
//     }
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         //         priority_queue<vector<int> , vector<vector<int>> , comp> pq;
//         //         // Merge K list with arr number and use sliging window 
//         int n = nums.size() ;
//         unordered_map<int , int>mp;
//         vector<pair<int, int>> v = mergeIntoOne(nums);
//         int i=0 ;
//         pair<int,int>ans;
//         ans.first = -100001;
//         ans.second = 100001;

        
//         for(int j=0 ; j < v.size() ; j++){
//             pair<int,int> curr = v[j];
//             mp[curr.second]++;
//             pair<int,int> newInterval = {v[i].first , curr.first};
//             if(mp.size() >= n ){
//                 cout<<newInterval.first<<"  "<<newInterval.second<<"  \n";
//                 if(isSmaller(newInterval , ans)){
//                     // cout<<"["<<newInterval.first<<","<<newInterval.second<<"] \n Is smaller than ans = \n";
//                     cout<<"["<<ans.first<<","<<ans.second<<"] \n";
//                     ans = newInterval;                
//                 }
//             }
//             // Sliding the window 
//                 while(mp.size() < n && j >=i){
//                 pair<int, int> p = v[i++];
//                 mp[p.second]--;
//                 if(mp[p.second]==0)
//                     mp.erase(p.second);
//                 }
//         }
//         return {ans.first , ans.second};
//     }
// };




class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int> newInterval = {0,INT_MAX} ;
        // pointers on lists 
        vector<int> ptrs(nums.size(),0) ;
        // min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        // vector of pairs <number,which list>
        vector<pair<int,int>> v; 
        
        // push first k elements in heap
        for(int i = 0 ; i < nums.size() ; i++) {
            // if pointer in range 
            if(ptrs[i] < nums[i].size() ){
                minHeap.push({nums[i][ptrs[i]],i});
            }
        }
        
        // sort array of pairs with heap
        while(minHeap.size()){
            pair<int,int> min  = minHeap.top();   
            minHeap.pop();
            v.push_back(min);
            ptrs[min.second] ++ ;
            if( ptrs[min.second] < nums[min.second].size() ) minHeap.push({nums[min.second][ptrs[min.second]],min.second});
        }     
        // slide window to get smalles subarray with k keys 
        int i = 0;
        unordered_map<int,int> mp ; // <index of list, number of elements from that list >
        for(int j = 0 ; j < v.size() ; j ++ ) {
            pair<int,int> rightMost = v[j];
            mp[rightMost.second] ++ ;
            // shrink 
            while(mp.size() == nums.size()) {
                // update answer 
                if(isSmaller({v[i].first,v[j].first},newInterval ) ){
                    newInterval = {v[i].first,v[j].first} ;
                }
                pair<int,int> left = v[i] ;
                mp[left.second] --;
                if(!mp[left.second]) mp.erase(left.second);
                i ++ ;
            }
        }
        return newInterval;
    }
    
    bool isSmaller(vector<int> a, vector<int> b ){
        if(a[1] - a[0] != b[1]-b[0]) return a[1] - a[0] < b[1]-b[0] ;
        return a[0] < b[0] ;   
    }
};

/*
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vi;
        
        struct comp {
            bool operator()(pair<vi, vi> p1, pair<vi, vi> p2) {
                return *p1.first > *p2.first;
            }
        };
        
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
        for (auto &row : nums) {
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            pq.push({row.begin(), row.end()});
        }
        
        vector<int> ans = {lo, hi};
        while (true) {
            auto p = pq.top();
            pq.pop();
            ++p.first;
            if (p.first == p.second)
                break;
            pq.push(p);
            
            lo = *pq.top().first;
            hi = max(hi, *p.first);
            if (hi - lo < ans[1] - ans[0])
                ans = {lo, hi};
        }
        return ans;
    }
};


*/
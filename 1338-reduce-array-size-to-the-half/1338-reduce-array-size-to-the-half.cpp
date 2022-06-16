// class Solution {
// public:
//     int minSetSize(vector<int>& arr) {
//         unordered_map<int, int> mp;
//         for(auto &it : arr)
//             mp[it]++;
//         int size= arr.size();
//         // occurance , number
//         priority_queue<pair<int , int>> pq;
//         for(auto &it : arr){
//             pq.push({mp[it] , it});
//         }
//         int ans =0 ;
//         while(size > arr.size() /2){
//             int currDelete = pq.top().first ;
//             int currElement = pq.top().second;
//             while(currElement == pq.top().second && !pq.empty())
//                 pq.pop();
//             size-=currDelete ;
//             ans++;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int MAX=1e5;
    int minSetSize(vector<int> &arr)
    {
        int fre[MAX + 1], bucket[MAX + 1];
        memset(fre, 0, sizeof(fre));
        memset(bucket, 0, sizeof(fre));
        int max_fre = 0;
        for(auto num : arr)
            max_fre = max(max_fre, ++fre[num]);
        for(int i = 1; i <= MAX; i++)
            bucket[fre[i]]++;

        int n = arr.size() / 2;
        int ans = 0;
        for(int i = max_fre; i > 0; i--)
        {
            if(!bucket[i])
                continue;
            if(n < 0)
                return ans;
            int freToDelete = min(bucket[i], n / i + (n % i > 0));
            n -= i * freToDelete;
            ans += freToDelete;
        }
        return ans;
    }
};

/*
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];

        vector<int> counting(n + 1);
        for (auto [_, freq] : cnt) ++counting[freq];

        int ans = 0, removed = 0, half = n / 2, freq = n;
        while (removed < half) {
            ans += 1;
            while (counting[freq] == 0) --freq;
            removed += freq;
            --counting[freq];
        }
        return ans;
    }
};

*/

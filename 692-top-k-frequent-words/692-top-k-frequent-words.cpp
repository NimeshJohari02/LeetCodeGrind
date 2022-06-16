class Solution {
public:
    class comp{
        public :
        bool operator()(const pair<string,int>& a, const pair<string,int>& b) {
            return a.second>b.second || (a.second==b.second && a.first  < b.first);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair< string , int  > , vector<pair<string , int >> , comp>pq;
        unordered_map<string , int> mp;
        for(auto &it : words)mp[it]++;
        for(auto &it : mp)
        {
            pq.push({it.first , it.second});
            if(pq.size()> k )pq.pop();
        }
        vector<string > ans;
        while(k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
         reverse(ans.begin() ,ans.end());
        
        return ans;
    }
};



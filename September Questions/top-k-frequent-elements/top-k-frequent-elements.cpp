

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>freqMap;
    for(int i=0;i<nums.size();i++)
    {
      freqMap[nums[i]]++;
    }
        //Creating a lambda function in cpp 
         auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
          return lhs.second < rhs.second;
    };
       priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);
      for(auto x:freqMap){
        pq.push(make_pair(x.first,x.second));
      }
      vector<int>ans;
      while(!pq.empty() and k-- ){
        ans.push_back(pq.top().first);
        cout<<pq.top().first<<" Second "<<pq.top().second<<endl;
        pq.pop();
      }
      return ans;
    }
};
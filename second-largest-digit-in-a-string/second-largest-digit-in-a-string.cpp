class Solution {
public:
    int secondHighest(string s) {
      priority_queue<int>pq;
      for(auto it : s){
        if(isdigit(it)){
          int num = it-'0';
          pq.push(num);
        }
      }
      if(pq.size()>=2){
      int firstLargest = pq.top();
        pq.pop();
        while(pq.top()==firstLargest and !pq.empty())
        {
          pq.pop();
        }
        if(pq.empty()){
          return -1;
        }
        int secondLargest = pq.top();
        return secondLargest;
      }
      return -1;
    }
};
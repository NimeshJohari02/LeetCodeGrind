class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int sum = 0;
      // storing number and window size 
        priority_queue<pair<int, int>> pq;
	    //make intial window
      for(int i = 0; i < k-1;i++){
            pq.push({nums[i], i + k - 1});
        }
      //travese over rest 
        vector<int> ans;
        for(int i = k-1;i < nums.size();i++){
            pq.push({nums[i], i + k - 1});
            while(pq.top().second < i){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
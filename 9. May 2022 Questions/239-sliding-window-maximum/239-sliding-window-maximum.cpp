class Solution {
public:
    vector<int>pqSolution(vector<int>&nums , int k ){
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int>ans; 
        deque<int>dq;
        for(int i=0 ; i < nums.size() ; i++){
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
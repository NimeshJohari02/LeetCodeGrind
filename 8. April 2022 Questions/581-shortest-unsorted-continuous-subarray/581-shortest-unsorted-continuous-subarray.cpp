class Solution {
public:
    // vector<int>getNSL(vector<int>&nums){
    //     int pseudoIdx = -1;
    //     vector<int>ans;
    //     stack<pair<int, int>> stk;
    //     for(int i=0 ; i < nums.size() ; i++){
    //         if(stk.empty()){
    //             ans.push_back(pseudoIdx);
    //         }
    //         else if(nums[i] > stk.top().first){
    //             ans.push_back(stk.top().second);
    //         }
    //         else if(!stk.empty() && nums[i] <= stk.top().first){
    //             while(!stk.empty() && nums[i] <= stk.top().first)
    //                 stk.pop();
    //             if(stk.empty()){
    //                 ans.push_back(pseudoIdx);
    //             }
    //             else{
    //                 ans.push_back(stk.top().second);
    //             }
    //         }
    //         stk.push({nums[i] , i});
    //     }
    //     return ans;
    // }
    // vector<int>getNGR(vector<int>&nums){
    //     int pseudoIdx = nums.size();
    //     vector<int>ans ;
    //     stack<pair<int , int>>stk;
    //     int n = nums.size();
    //     for(int i= n-1 ; i >=0 ; i--){
    //         if(stk.empty()){
    //             ans.push_back(pseudoIdx);
    //         }
    //         else if(nums[i] <= stk.top().first){
    //             ans.push_back(stk.top().second);
    //         }
    //         else if(!stk.empty() && nums[i]> stk.top().first){
    //             while(!stk.empty() && nums[i]> stk.top().first)
    //                 stk.pop();
    //             if(stk.empty())
    //                 ans.push_back(pseudoIdx);
    //             else 
    //                 ans.push_back(stk.top().second);
    //         }
    //      stk.push({nums[i] , i });   
    //     }
    //     reverse(ans.begin() , ans.end());
    //     return ans;
    // }
    int findUnsortedSubarray(vector<int>& nums) {
          int n = nums.size(); 
        int l = n, r = 0; 

        stack<int> temp; 
        //ngl
        for(int i = 0; i < n; i++) {
            while(!temp.empty() and nums[temp.top()] > nums[i]) {
                l = min(l, temp.top()); 
                temp.pop();
            }
            temp.push(i); 
        }

        temp = stack<int>(); 
        // nsr idx 
        for(int i = n-1; i > -1; i--) {
            while(!temp.empty() and nums[temp.top()] < nums[i]) {
                r = max(r, temp.top()); 
                temp.pop(); 
            }

            temp.push(i);
        }
        return r-l>0?r-l+1:0;
        
        
    }
};
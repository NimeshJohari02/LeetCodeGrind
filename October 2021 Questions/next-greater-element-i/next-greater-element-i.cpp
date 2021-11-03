class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        vector<int>ans;
        for(int i=nums2.size()-1;i>=0;i--){
            if(stk.empty()){
                ans.push_back(-1);
            }
            else if(!stk.empty() and stk.top()>nums2[i]){
                ans.push_back(stk.top());
            }
            else if (!stk.empty() and stk.top()<nums2[i]){
                while(!stk.empty() and stk.top()<nums2[i]){
                    stk.pop();
                }
                if(stk.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(stk.top());
                }
            }
            stk.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        map<int,int>elngr;
        for(int i =0;i<nums2.size();i++){
            elngr[nums2[i]]=ans[i];
        }
        vector<int>miniAns;
        for(auto it : nums1){
            miniAns.push_back(elngr[it]);
        }
        return miniAns;
    }
};
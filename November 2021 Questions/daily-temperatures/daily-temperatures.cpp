class Solution {
public:
    //nearest greater to right with index variation 
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>ans;
        // 1->Number 2->idx
        stack<pair<int,int>>stk;
        for(int i = arr.size()-1 ; i>=0 ; i--){
            if(stk.empty()){
                ans.push_back(0);
            }
            else if(!stk.empty() and arr[i]<stk.top().first){
                ans.push_back(stk.top().second-i);
            }
            else if(!stk.empty() and arr[i]>=stk.top().first){
                while(!stk.empty() and arr[i]>=stk.top().first){
                    stk.pop();
                }
                if(stk.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(stk.top().second-i);
                }
            }
            stk.push({arr[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
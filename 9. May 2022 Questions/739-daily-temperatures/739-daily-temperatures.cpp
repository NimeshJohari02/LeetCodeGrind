class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> stk ;
        int n = arr.size();
        vector<int> nge(n ,0 );
        for(int i=n-1 ; i >=0 ; i--){
            while(!stk.empty() && arr[i] >= arr[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                nge[i] = 0 ;
            }
            else nge[i] =  stk.top() - i ;
            stk.push(i);
        }
            return nge;
    }
};
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // every idx can be at places n-i-1 not more 
        stack<int> stk;
        int j =0 ;
        for(int i=0 ; i < pushed.size() ; i++){
            stk.push(pushed[i]);
            while(!stk.empty() && stk.top() == popped[j]){
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};
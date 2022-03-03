class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        vector<bool>visited(arr.size(), false); 
        while(!q.empty()){
            int idx = q.front();
            int val = arr[idx];
            q.pop();
            if(!visited[idx]){
                visited[idx]=true;
            if(val==0)
                return true;
            if(idx+val<arr.size())
                q.push(idx+val);
            
            if(idx-val>=0){
                q.push(idx-val);
            }
        }
        }
        return false;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int rows = mat.size() , cols = mat[0].size();
        // solider , idx;
        for(int i=0 ; i < rows ; i++)
        {
            int cs  =0 ;
            for(int j =0 ; j < cols ; j++)
                cs+=mat[i][j];
            pq.push({cs , i});
        }
        vector<int>ans;
        while(!pq.empty() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
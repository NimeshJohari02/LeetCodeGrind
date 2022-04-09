class Solution {
public:
// THERE IS NO NEED FOR BFS YOU JUST NEED TO CHECK THE INDEGREE .
    // If indegree ==0 then add to ans; not bfs
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans, indegree(n , 0);
        for(auto &it : edges) indegree[it[1]]++;
        for(int i=0 ; i < n ; i++) if(indegree[i] == 0 ) ans.push_back(i);
        return ans;
    }
};
/*
credits to @emmm_
"Basic idea: the roots of MHT must be the mid points of the longest leaf to leaf path in the tree.
And to find the longest path, we can first find the farthest leaf from any node, and then find
the farthest leaf from the node found above. Then these two nodes we found are the end points
of the longest path. And last, we find the centers of the longest path."

Steps:

1.Create adjcent list(neighbors)

2.Count in-degree of all vertices.

3.Pick any vertex 'v' which has in-degree of 0.

4.Print 'v'. Remove the vertex 'v' and all edges coming out of it. Decrement in-degrees of all neighbors of vertex 'v' by 1.

5.Repeat steps 3 and 4 till u either have just 1 or 2 nodes available.
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return {};
        if(n==1) return {0};
        vector<int> res ;
        vector<int> indegree(n+1 , 0);
        vector<vector<int>>adj(n);
        for(int i=0 ; i < edges.size()  ;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][1]]++;
            indegree[edges[i][0]]++;
        }
        queue<int>q;
        for(int i=0 ; i < n ; i++){
            if(indegree[i] ==1 ) q.push(i);
        }
        while(!q.empty()){
            int k = q.size();
            res.clear();
            for(int i =0 ; i < k ; i++){
                auto node = q.front();
                q.pop();
                res.push_back(node);
                for(auto &it : adj[node]){
                    indegree[it]--;
                    if(indegree[it] == 1) q.push(it);
                }
            }
        }
        return res ;
        }
};
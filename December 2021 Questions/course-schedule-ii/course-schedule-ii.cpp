class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        for(auto &x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        // topological sort
        queue<int>que;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                que.push(i);
            }
        }
        
        vector<int>res;
        while(!que.empty())
        {
            int node = que.front();
            que.pop();
            res.push_back(node);
            for(int &x : adj[node])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    que.push(x);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();        
    }
};
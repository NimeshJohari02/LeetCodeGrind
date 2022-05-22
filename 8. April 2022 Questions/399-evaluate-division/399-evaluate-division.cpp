class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> adj;
        for(int i=0;i<equations.size();i++)
        {
            adj[equations[i][0]].insert({equations[i][1],values[i]});
            adj[equations[i][1]].insert({equations[i][0],(double)1/values[i]});
        }
        vector<double> res(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> visited;
            res[i]=dfs(queries[i][0],queries[i][1],visited,adj);
        }
        return res;
        
    }
    
    double dfs(string start,string end,unordered_set<string>& visited,unordered_map<string,unordered_map<string,double>>& adj)
    {
        if(adj.find(start)==adj.end())
            return -1.0;
        if(adj[start].find(end)!=adj[start].end())
            return adj[start][end];
        visited.insert(start);
        for(auto & it:adj[start])
        {
            if(!visited.count(it.first))
            {
                double ans=dfs(it.first,end,visited,adj);
                if(ans!=-1.0)
                    return (double)ans * (it.second);
            }       
        }
        return -1.0;
    }
};
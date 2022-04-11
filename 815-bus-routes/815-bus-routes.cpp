class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& v, int src, int dest) 
    {
        map<int,vector<int>>mp;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                mp[v[i][j]].push_back(i);
            }
        }
        queue<int>q;
        q.push(src);
        unordered_map<int,int>nodeVisited;
        unordered_map<int,int>busVisited;
        nodeVisited[src]++;
        int level=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                auto node=q.front();
                q.pop();
                if(node==dest){
                    return level;
                }
                for(auto& x:mp[node]){
                    if(busVisited.find(x)==busVisited.end())
                    {
                        for(int i=0;i<v[x].size();i++)
                        {
                            if(nodeVisited.find(v[x][i])==nodeVisited.end())
                            {
                                q.push(v[x][i]);
                                nodeVisited[v[x][i]]++;
                            }
                        }
                        busVisited[x]++;
                    }
                }
            }
            level++;
        }
        return -1;
        
    }
};
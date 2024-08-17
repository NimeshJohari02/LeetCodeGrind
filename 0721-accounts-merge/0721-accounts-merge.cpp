class DSU {
 private:
  vector<int> parent, size;

 public:
  DSU(int n) {
      size = vector<int>(n , 1);
    for (int i = 0; i < n; i++) {
      parent.push_back(i);
    }
  }
  // This is known as union by size
  int findParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
  }
  void Union(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    if (pu == pv) return;
    if (size[pu] < size[pv]) {
      parent[pu] = pv;
      size[pv] += size[pu];
    } else {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr){
        int n = arr.size() ;
        unordered_map<string , int > mp;
        DSU ds(n);
        for(int i=0 ; i < n ; i++)
        {
            for(int j =1 ; j < arr[i].size() ; j++){
                string emailId = arr[i][j];
                if(mp.find(emailId) == mp.end()){
                    mp[emailId] = i ;
                }
                else{
                    ds.Union(i , mp[emailId]);
                }
            }
        }
        vector<string>mergedMail[n];
        for(auto &it : mp){
            auto emailId = it.first;
            int node = ds.findParent(it.second) ;
            mergedMail[node].push_back(emailId);
        }
        vector<vector<string>>ans ;
        for(int i=0 ; i < n ; i++){
            auto mailList = mergedMail[i];
            if(mailList.size() != 0 ){
                sort(mailList.begin() , mailList.end());
                vector<string>miniAns ;
                miniAns.push_back(arr[i][0]);
                for(auto &it : mailList)miniAns.push_back(it);
                ans.push_back(miniAns);
            }
        }
        return ans ;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>ip, vector<int>subset , int k, int index){
        if(subset.size()==k){
         ans.push_back(subset);   
        }
        for(int i=index ; i<ip.size(); i++){
            subset.push_back(ip[i]);
            helper(ip,subset ,k , i+1);
            subset.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ip(n);
        for(int i=1 ; i<=n ; i++){
            ip[i-1]=i;
        }
        vector<int>subset;
        helper(ip, subset , k , 0);
        return ans ;
    }
};
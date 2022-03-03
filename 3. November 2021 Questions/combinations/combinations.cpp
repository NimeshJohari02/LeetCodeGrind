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


// Better 
class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>&subset , int index , int n , int k){
        if(subset.size()==k){
         ans.push_back(subset);   
            return;
        }
        for(int i=index ; i<=n; i++){
            subset.push_back(i);
            helper(subset ,i+1,n ,k);
            subset.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset;
        helper( subset ,1,n, k );
        return ans ;
    }
};

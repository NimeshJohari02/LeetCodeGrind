class Solution {
public:
    vector<vector<int>>ans;
    void helper(int num  ,  vector<int>&ds , int cs , int k ){
        if(cs ==0 && ds.size() == k) {ans.push_back(ds) ; return ;}
        if(cs <0 || num >=10) return ;        
        ds.push_back(num);
        helper(num +1 , ds , cs - num , k);
        ds.pop_back();
        helper(num+1 , ds , cs , k );
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        helper(1, ds ,n ,  k );
        return ans;
    }
};
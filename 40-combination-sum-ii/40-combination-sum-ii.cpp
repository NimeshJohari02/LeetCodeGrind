class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx , vector<int>&ds , int tgt , vector<int>&arr){
        if(tgt ==0 ) {
            ans.push_back(ds);
            return ; 
        }
        for(int i = idx; i < arr.size() ; i++){
            if(i > idx && arr[i] == arr[i-1]) continue ;
            if(tgt < arr[i]) break;
            ds.push_back(arr[i]);
            helper(i+1 , ds , tgt- arr[i] , arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int idx =0 ;
        vector<int> ds;
        sort(candidates.begin() , candidates.end());
        helper(idx , ds , target , candidates);
        return ans;
    }
};
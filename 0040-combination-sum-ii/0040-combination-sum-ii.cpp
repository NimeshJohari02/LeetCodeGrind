class Solution {
public:
    void helper(int idx , int target , vector<int>&ds , vector<vector<int>>&ans , vector<int>&arr){
        if(target == 0){
            ans.push_back(ds);
            return ;
        }
        for(int i = idx ; i < arr.size() ; i++)
        {
            if(arr[i]>target)break ;
            if(i > idx && arr[i]==arr[i-1])continue;
            ds.push_back(arr[i]);
            helper(i+1 , target-arr[i] , ds , ans , arr);
            ds.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        vector<int>ds ;
        vector<vector<int>>ans ;
        helper(0 , target , ds , ans , arr);
        return ans ; 
    }
};
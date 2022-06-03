class Solution {
public:
    vector<vector<int>> ans;
    void helper( vector<int>&ds , vector<int>&arr , vector<int>&freq){
        if(ds.size() == arr.size()) {
            ans.push_back(ds);
            return ;
        }
        for(int i= 0  ; i < arr.size() ; i++){
            if(!freq[i]){
                ds.push_back(arr[i]);
             freq[i]=1;
                helper(ds , arr , freq);
                ds.pop_back();
                freq[i] =0 ;
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds ;
        int n = nums.size();
        vector<int>freq(n , 0 );
        helper(ds , nums , freq);
        return ans;
    }
};
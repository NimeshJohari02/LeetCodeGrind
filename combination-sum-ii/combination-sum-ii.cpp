class Solution {
public:
    
    vector<vector<int>> ans;
    void helper(vector<int>&ip , vector<int>&subset , int index , int target){
        if(target == 0){
            ans.push_back(subset);
            return ;
        }
        for(int i = index ; i<ip.size() ; i++){
                if(ip[i]>target) return;
                if(i&&ip[i]==ip[i-1]&&i>index) continue; // check duplicate combination
                subset.push_back(ip[i]),
                helper(ip,subset,i+1,target-ip[i]); // recursive componenet
                subset.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& ip, int target) {
        vector<int>subset;
        sort(ip.begin(),ip.end());
        helper(ip,subset, 0 , target);
        return ans;
    }
};
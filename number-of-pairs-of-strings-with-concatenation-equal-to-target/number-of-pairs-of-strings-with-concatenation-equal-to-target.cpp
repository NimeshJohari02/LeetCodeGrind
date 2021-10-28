class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        set<pair<int, int>> ans; 
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                string temp = nums[i] + nums[j]; 
                if(temp == target && i!= j){
                    ans.insert({i,j});
                }
            }
        }
        
        return ans.size(); 
    }
};
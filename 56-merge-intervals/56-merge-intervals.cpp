class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<vector<int>>& arr){
        for(int i=0 ; i < arr.size() ; i++){
            auto  currInterval = arr[i];
            if(ans.empty() || ans.back()[1] < currInterval[0])ans.push_back(currInterval);
            else{
                ans.back()[1] = max(ans.back()[1] , currInterval[1]);
            }
        }
        
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        helper(intervals);
        return ans;
        
    }
};
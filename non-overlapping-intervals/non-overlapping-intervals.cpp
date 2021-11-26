class Solution {
public:
     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        
        sort(intervals.begin(), intervals.end(), [] (const vector<int> & lhs, const vector<int> & rhs) {
            return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });
        
        int ans = 0;
        int end = intervals[0][1];
        for (int i = 1; i < N; i++) {            
            if (intervals[i][0] < end) {
                ans++;
                end = min(end, intervals[i][1]);
            }
            else {
                end = intervals[i][1];
            }         
        }       
        
        return ans;        
    }
};
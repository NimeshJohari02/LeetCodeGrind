class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int mini = -1 ;
        int maxi = -1;
        int res =0 ;
        for(auto&it : intervals){
            if(it[0]>mini && it[1]>maxi){
                mini = it[0];
                res++;
            }
        maxi = max(maxi , it[1]);
        }
         return res;
    }
};
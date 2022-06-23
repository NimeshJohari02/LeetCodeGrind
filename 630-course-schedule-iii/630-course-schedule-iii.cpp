class Solution {
public:
    int numCourses(int idx , vector<vector<int>>&arr , int startDay ){
        if(idx == arr.size()) return 0;
        int take = 0;
        int notTake = numCourses(idx+1 , arr , startDay);
        if (startDay + arr[idx][0] < arr[idx][1])
            take = 1 + numCourses(idx+1, arr , startDay+arr[idx][0]);
        return max(take , notTake);

    }
    static bool cmp(vector<int>&v1 , vector<int> &v2){
        return v1[1] < v2[1];
    }
    int memo(int idx , int startDay , vector<vector<int>>&arr , vector<vector<int>>&dp){
        if(idx == arr.size()) return 0;
        int take = 0;
        if(dp[idx][startDay] != -1) return dp[idx][startDay];
        int notTake = memo(idx+1 , startDay ,arr , dp);
        if (startDay + arr[idx][0] < arr[idx][1])
            take = 1 + memo(idx+1, startDay + arr[idx][0] ,  arr , dp);
        return dp[idx][startDay]  = max(take , notTake);
    }
    // int tabulation(vector<vector<int>>&arr){
    //     sort(arr.begin() , arr.end() , cmp);
    //     vector<vector<int>>dp(arr.size()+3  , vector<int>(arr.back()[0]+3 , 0));
    //     for(int idx = arr.size()-1 ; idx >=0 ; idx--){
    //         for(int startDay = 0 ; startDay <= arr.back()[0] ; startDay++){
    //             int notTake = dp[idx+1][startDay];
    //             int take = 0 ;
    //             if (startDay + arr[idx][0] < arr[idx][1])
    //                 take = 1 + dp[idx+1][startDay + arr[idx][0]];
    //              dp[idx][startDay]  = max(take , notTake);
    //         }
    //     }
    //     return dp[0][0];
    // }
    
    int greedy(vector<vector<int>>&arr){
        sort(arr.begin() , arr.end()  , cmp);
        priority_queue<int> pq ;
        int startDay = 0 ;
        for(auto &it : arr){
            if(it[0] + startDay <= it[1])
                startDay += it[0]  , pq.push(it[0]);
            else if(!pq.empty() && pq.top() >  it[0])
                startDay += it[0] - pq.top() , pq.pop() , pq.push(it[0]); 
        }
        return pq.size();
    }
    int scheduleCourse(vector<vector<int>>& arr) {
        // recursion
        // sort(arr.begin() , arr.end() , cmp);
        // return numCourses(0 , courses , 0);
        // vector<vector<int>>dp(arr.size() , vector<int>(arr.back()[0] , -1));
        // return memo(0 , 0 , arr , dp );
        // return tabulation(arr);
        return greedy(arr);
    }
};
class Solution {
public:
    int dp[102][102]={};
    int MCM(vector<int>&cuts , int start , int end ){
       if(end-start<=1) 
           return 0;
        if(!dp[start][end]){
            dp[start][end]= INT_MAX;
            for(int partition = start+1 ; partition < end ; partition++){
                dp[start][end]= min(dp[start][end], cuts[end]-cuts[start]+MCM(cuts , start , partition) + MCM(cuts , partition , end));
            }
        }
        return dp[start][end];
    }
    int minCost(int n, vector<int>& cuts) {
        // Addiing extra cut for 0 
        cuts.push_back(0);
        // Adding Extra Cut for end of stick
        cuts.push_back(n);
        
        sort(cuts.begin() , cuts.end());
        return MCM(cuts, 0 , cuts.size()-1);
        
    }
};


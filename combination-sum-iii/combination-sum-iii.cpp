class Solution {
public:
    vector<vector<int>> ans ;
    void helper(vector<int>ip , vector<int>subset, int k , int targetSum ){
        if(ip.empty()){
            if(subset.size()==k && targetSum ==0){
                ans.push_back(subset);
            }
            return;
        }
        
        vector<int>c1(subset.begin(),subset.end());
        vector<int>c2(subset.begin(),subset.end());
        int temp = ip.back();
        c1.push_back(temp);
        ip.pop_back();
        helper(ip , c1 , k , targetSum-temp);
        helper(ip , c2 , k , targetSum);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<int>ip(9);
     vector<int>subset;
        
        for(int i=1 ; i<=9;i++){
            ip[i-1]=i;
        }
        helper(ip,subset , k , n );
        return ans;
    }
};
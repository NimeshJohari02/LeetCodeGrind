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



// Optimised Approach Using For Loop based Backtracking 


class Solution {
public:
 vector<vector<int>> ans;
vector<vector<int>> combinationSum3(int k, int n){
    //k numbers sum to n
    vector<int> subset;
    helper(n, subset, 1, k);
    return ans;
}

void helper(int target, vector<int> &subset, int begin, int count){
    if  (target==0) {
        ans.push_back(subset);
        return;
    }
  
    if (count==0)
        return;
    
    for (int i=begin; i<10 && target>=i*count+count*(count-1)/2; i++) {
        subset.push_back(i);
        helper(target-i, subset, i+1, count-1); 
        subset.pop_back();
    }
}

};

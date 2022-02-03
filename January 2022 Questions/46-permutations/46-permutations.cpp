class Solution {
    private:
    vector<vector<int>>ans;
    map<int,int>freq;
    void generator(vector<int>&subset , vector<int>&nums){
        if(subset.size() == nums.size())
        {
            ans.push_back(subset);
        return ;
        }
        for(int idx =0 ; idx <nums.size() ; idx++){
            // Here the freq map acts like visited / available to pick flag and we are right now storing idx in this as duplicates are allowed , 
            // If we are to not include duplicates we use the freq[arr[idx]] in place of freq[idx]
            if(!freq[idx]){
                subset.push_back( nums[idx]);
                freq[idx]=1;
                generator(subset , nums);
                freq[idx]=0;
                subset.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>subset;
        generator(subset , nums);
        return ans;
    }
};

/*
Optimal Approach Without using map 
class Solution {
public:
    vector<vector<int>>ans;
    void getPermutation(vector<int>nums , int i=0){
        if(i==nums.size()-1){
            ans.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            // here we run from j =idx or i till size because we have to swap with aage ke elements
            swap(nums[i],nums[j]);
            getPermutation(nums,i+1);
            //Backtrack
            swap(nums[i],nums[j]);
        }
    return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        getPermutation(nums,0);
        return ans;
    }
};


*/
/*class Solution {
public:
    set<vector<int>>ans;
    void helper(vector<int>nums , vector<int>output ){
    if(nums.empty()){
        // sort(output.begin(),output.end());
        ans.insert(output);
        return;
    }
        vector<int>op1(output.begin(),output.end());
        vector<int>op2(output.begin(),output.end());
        op1.push_back(nums.back());
        nums.pop_back();
        helper(nums , op1);
        helper(nums , op2);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr;
        sort(nums.begin(),nums.end());
        vector<int>dummy;
        helper(nums,dummy);
        for(auto it : ans){
            arr.push_back(it);
        }
        return arr;
    }
};*/

// Optimised Soln 
class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
    }
private:
	void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) { 
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};
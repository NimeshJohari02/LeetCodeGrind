class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      int size = nums.size();
      vector<int>ans;
      int *arr = new int[size+1]{0};
      for(auto x : nums){
        arr[x]++;
      }
      for(int i=1;i<=size;i++){
        if(arr[i]==0){
          ans.push_back(i);
        } 
      }
      return ans;
      }
};
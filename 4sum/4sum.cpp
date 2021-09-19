class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
      if(nums.size()<4){
        return {};
      }
      vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
      for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
          int secondTarget=target-(nums[i]+nums[j]);
          int lo = j+1;
          int hi = n-1;
          while(hi>lo){
            int Sum = nums[lo]+nums[hi];
            if(Sum > secondTarget){
              hi--;
            }
            else if(Sum < secondTarget){
              lo++;
            }
            else{
              vector<int> quad={nums[i],nums[j],nums[lo],nums[hi]};
              ans.push_back(quad);
               while(lo<hi && quad[2] == nums[lo]) {
                            lo++;
                        }
                        
                        while(lo<hi && nums[hi] ==quad[3] ) {
                            hi--;
                        }
                        
                        while(j+1<n && nums[j+1] == quad[1]) {
                            j++;
                        }
                        
                        while(i+1<n-1 && nums[i+1] == quad[0]) {
                            i++;
                        }
            }
          }
        }
      }
      return ans;
    }
};
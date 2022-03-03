class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
//O(n2)
      //     int count =0;
  //     for(int i=0;i<nums.size()-1;i++){
  //   for(int j=i+1;j<nums.size();j++){
  //     if(abs(nums[j]-nums[i])==k){
  //       count++;
  //     }
  //   }
  // }
  //     return count;
      //Optimised Approach;
      map<int,int>mp;
      int count =0;
      for(auto it : nums ){
        if(mp[it-k]){
          count +=mp[it-k];
        }
        if(mp[it+k]){
          count +=mp[it+k];
        }
        mp[it]++;
      }
    return count ;
    }
};

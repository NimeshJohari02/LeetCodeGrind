//i#include<bits/stdc++.h>
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
      int n = nums.size();
      vector<int>ans;
      int prevSum=0;
      int sumfromBack=0;
      for(int i=0;i<n;i++){
        sumfromBack+=nums[i];
      }
      for(int i=0;i<n;i++){
        int ca = (nums[i]*i-prevSum)+(sumfromBack-(nums[i]*(n-i)));
        prevSum+=nums[i];
        sumfromBack-=(nums[i]);
        ans.push_back(ca);
      }
      return ans;
    }
};
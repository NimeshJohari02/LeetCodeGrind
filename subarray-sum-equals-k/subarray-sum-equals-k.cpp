class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int currSum =0;
      int count=0;
      map<int,int>storeMap;
      storeMap[0]++;
      for(auto i : nums){
        currSum+=i;
        count+=storeMap[currSum-k];
        storeMap[currSum]++;
      }
      //cout<<storeMap[1000];
      for(auto i : storeMap){
        cout<<i.first<<"    "<<i.second<<"  "<<endl;
      }
      return count;
    }
};